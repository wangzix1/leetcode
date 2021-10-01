#include <iostream>
#include <vector>

using namespace std;

class MinHeap{
public:
	int peek() const {return data_[0];}
	int pop(){
		swap(data_.back(), data_[0]);
		int min_el = data_.back();
		data_.pop_back();
		heapifyDown(0);
		return min_el;
	}

	void push(int key){
		data_.push_back(key);
		heapifyUp(data_.size() - 1);
	}

	int size() const{
		return data_.size();
	}
private:
	void heapifyUp(int index){
		if (index == 0) return;
		int parent = (index-1)/2;
		if (data_[index] >= data_[parent]) return;
		swap(data_[index], data_[parent]);
		heapifyUp(parent);
	}
	void heapifyDown(int index){
		int left = 2*index+1;
		int right = 2*index+2;
		if (left >= data_.size()) return;
		int min_child = right < data_.size() && data_[right] < data_[left] ? right: left;
		if (data_[index] <= data_[min_child]) 
			return;
		swap(data_[index], data_[min_child]);
		heapifyDown(min_child);
	}
	vector<int>data_;

};


int main(){
	vector<int> data{5,1,3,5,3,4,3,7};
	MinHeap heap;
	for (int x: data)
		heap.push(x);
	vector<int> output;
	while(heap.size())
		output.push_back(heap.pop());
	cout << heap.size() << endl;
	assert(output == vector<int>({1,3,3,3,4,5,5,7}));

}
