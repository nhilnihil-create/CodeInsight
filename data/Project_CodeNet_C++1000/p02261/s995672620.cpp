#include <cstdio>
#include <iostream>

using namespace std;

struct card {
	char c;
	int v;
};

void BubbleSort(card A[], int n) {

	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j > i; --j) {
			if (A[j - 1].v > A[j].v)
				swap(A[j - 1], A[j]);
		}
	}

}

void SelectionSort(card A[], int n) {
	for (int i = 0; i < n; ++i) {
		int minIdx = i;
		int minv = A[i].v;
		for (int j = i + 1; j < n; ++j) {
			if (A[j].v < minv) {
				minv = A[j].v;
				minIdx = j;
			}
		}
		swap(A[i], A[minIdx]);
	}
}

int main() {

	int n;
	scanf("%d", &n);

	card A[n];
	for (int i = 0; i < n; ++i) {
		char c;
		int v;
		cin >> c >> v;
		card cd;
		cd.c = c;
		cd.v = v;
		A[i] = cd;
	}
	card B[n];

	for (int i = 0; i < n; ++i) {
		B[i] = A[i];
	}

	BubbleSort(A, n);

	for (int i = 0; i < n; ++i) {
		if (i != 0)
			cout << " " << A[i].c << A[i].v;
		else
			cout << A[i].c << A[i].v;

	}
	cout << endl << "Stable" << endl;

	SelectionSort(B, n);
	for (int i = 0; i < n; ++i) {
		if (i != 0)
			cout << " " << B[i].c << B[i].v;
		else
			cout << B[i].c << B[i].v;
	}
	cout << endl;

	//check A
	bool stable = true;
	for (int i = 0; i < n; ++i) {
		if (A[i].c != B[i].c || A[i].v != B[i].v) {
			cout << "Not stable" << endl;
			stable = false;
			break;
		}
	}
	if (stable)
		cout << "Stable" << endl;

	return 0;
}