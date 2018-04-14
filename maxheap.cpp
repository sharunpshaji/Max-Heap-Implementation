#include <iostream>
using namespace std;

class maxHeap{
private:
	int array[100];
	int length;
public:
	maxHeap() {
		length = -1;
	}
	void insert(int value);
	void swap(int indexOne, int indexTwo);
	void delete_root();
	void display();
};

//swap() function to swap two places along the array
void maxHeap::swap(int indexOne, int indexTwo) {
	int x = array[indexTwo];
	array[indexTwo] = array[indexOne];
	array[indexOne] = x;
}

//display() function to display the elements of the heap
void maxHeap::display() {
	for (int i = 0; i <= length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void maxHeap::insert(int value) {
	length++;
	int i = length;
	int parentIndex = i;
	array[length] = value;
	//Now compare it with its parent, and keep doing it till root is reached
	while (parentIndex != 0) {
		i = parentIndex;
		parentIndex = (parentIndex-1)/2;
		if (array[parentIndex] < array[i]) {
			swap(parentIndex, i);
		}
	}
}

void maxHeap::delete_root() {
	//Copy the last element to the root
	array[0] = array[length];
	//Remove the last element
	array[length] = array[length + 1];
	length--;
	int index = 0;
	int leftChild = 2*index + 1;
	while (array[leftChild] != array[length + 1]) {
		int leftChild = 2*index + 1;
		int rightChild = 2*index + 2;
		//Has only one child
		if (array[rightChild] == array[length + 1]) {
			if (array[index] < array[leftChild]) {
				swap(leftChild, index);
				index = leftChild;
			}
			else {
				break;
			}
		}
		//Has two children
		else {
			if (array[leftChild] < array[rightChild] && array[index] < array[rightChild]) {
				swap(rightChild, index);
				index = rightChild;
			}
			else if (array[rightChild] < array[leftChild] && array[index] < array[leftChild]) {
				swap(leftChild, index);
				index = leftChild;
			}
			else {
				break;
			}
		}
	}
}

int main() {
	maxHeap newHeap;
	newHeap.insert(35);
	newHeap.insert(30);
	newHeap.insert(40);
	newHeap.display();
	newHeap.delete_root();
	newHeap.display();
	newHeap.delete_root();
	newHeap.display();
	return 0;
}
