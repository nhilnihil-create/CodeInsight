#include <algorithm>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int cnt = 0;
int A[1000000];

void insertionSort(int A[], int n, int g) {
	int v, j;
	for (int i = g; i < n; i++) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			swap(A[j + g], A[j]);
			j -= g;
			cnt++;
		}

		A[j + g] = v;
	}
}

void shellSort(int A[], int n) {
	vector<int> G;
	for (int h = 1; ; ) {
		if (h > n) break;
		G.push_back(h);
		h = h * 3 + 1;
	}

	cout << G.size() << "\n";

	for (int i = 0; i < G.size(); i++) {
		if (i > 0) cout << " ";
		cout << G[G.size() - i - 1];
	}
	cout << "\n";

	for (int i = 0; i < G.size(); i++) {
		insertionSort(A, n, G[G.size() - i - 1]);
	}
	cout << cnt << "\n";

	for (int i = 0; i < n; i++) {
		cout << A[i] << "\n";
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	shellSort(A, n);
}

