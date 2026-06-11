#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<map>

using namespace std;

const int MAX_SIZE = 2000001;

class PriorityQueue {
public:
	PriorityQueue() {
		for (int i = 0; i < MAX_SIZE; i++) {
			heap[i] = 0;
		}
		size = 0;
	}
	void insert(int n) {
		size++;
		heap[size] = n;
		
		int s = size;
		while (s > 1) {
			if (heap[s / 2] < heap[s]) {
				swap(heap[s / 2], heap[s]);
			}
			s /= 2;
		}
	}
	int extract() {
		long long res = heap[1];
		heap[1] = heap[size];
		size--;
		maxHeap(1);
		return res;
	}
	void maxHeap(int i) {
		int l = i * 2;
		int r = i * 2 + 1;
		int temp = i;
		if (l <= size && heap[temp] < heap[l]) {
			temp = l;
		}
		if (r <= size && heap[temp] < heap[r]) {
			temp = r;
		}
		if (temp != i) {
			swap(heap[temp], heap[i]);
			maxHeap(temp);
		}
	}

private:
	long long heap[MAX_SIZE];
	int size;
};

int main() {
	PriorityQueue pq;

	while (true) {
		string buf;
		int num;

		cin >> buf;
		if (buf == "end")break;
		else if (buf == "insert") {
			cin >> num;
			pq.insert(num);
		}
		else if (buf == "extract") {
			cout << pq.extract() << endl;
		}
	}
	return 0;
}