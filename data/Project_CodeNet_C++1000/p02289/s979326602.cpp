#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int H, A[2000000];

int parent(int i) {
	return i / 2;
}

int left(int i) {
	return 2 * i;
}

int right(int i) {
	return 2 * i + 1;
}

void maxHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l <= H && A[l] > A[i]) {
		largest = l;
	}
	if (r <= H && A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i) {
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(largest);
	}
}

void insert(int key) {
	int i = ++H;
	A[i] = key;
	int p = parent(i);
	while (i > 1 && A[p] < A[i]) {
		int temp = A[p];
		A[p] = A[i];
		A[i] = temp;
		i = p;
		p = parent(i);
	}
}

int heapExtractMax() {
	int max = A[1];
	A[1] = A[H];
	H--;
	maxHeapify(1);

	return max;
}

int main() {
	H = 0;
	string com;
	int k;
	cin >> com;
	while (com != "end") {
		if (com == "insert") {
			cin >> k;
			insert(k);
		}
		if (com == "extract") {
			cout << heapExtractMax() << endl;
		}
		cin >> com;
	}
	return 0;
}