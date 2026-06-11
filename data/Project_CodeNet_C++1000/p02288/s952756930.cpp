#include <iostream>
#include <vector>

void Swap(std::vector<int>& Heap, int IndexA, int IndexB)
{
	int Temp = Heap[IndexA - 1];
	Heap[IndexA - 1] = Heap[IndexB - 1];
	Heap[IndexB - 1] = Temp;
}

void MaxHeapify(std::vector<int>& Heap, unsigned int Index)
{
	unsigned int Left = 2 * Index;
	unsigned int Right = 2 * Index + 1;
	unsigned int Largest;
	if(Left <= Heap.size() && Heap[Left - 1] > Heap[Index - 1]){
		Largest = Left;
	}else{
		Largest = Index;
	}
	
	if(Right <= Heap.size() && Heap[Right - 1] > Heap[Largest - 1]){
		Largest = Right;
	}
	
	if(Largest != Index){
		Swap(Heap, Largest, Index);
		MaxHeapify(Heap, Largest);
	}
}

void BuildMaxHeap(std::vector<int>& Heap)
{
	for(unsigned int i = Heap.size() / 2; i > 0; --i){
		MaxHeapify(Heap, i);
	}
}

int main()
{
	int Count = 0;
	std::cin >> Count;
	std::vector<int> Heap(Count);
	for(int i = 0; i < Count; ++i){
		std::cin >> Heap[i];
	}
	
	BuildMaxHeap(Heap);
	
	for(int i = 0; i < Count; ++i){
		std::cout << " " << Heap[i];
	}
	std::cout << std::endl;
	
	return 0;
}