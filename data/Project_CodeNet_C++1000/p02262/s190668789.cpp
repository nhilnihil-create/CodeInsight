#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#define BIG 1000000000
#define BIGNUM 1000000
#define SIZE 1000
using namespace std;

int cnt = 0;

void insertionSort(int *A, int n, int g) {
	for (int i = g; i < n; i++) {
		int t = A[i];
		int j;
		for (j = i - g; j >= 0 && A[j] > t;cnt++,j-=g)
			A[j + g] = A[j];
		A[j + g] = t;
	}
}

void shellSort(int *A, int n) {
	cnt = 0;
	stack<int> s;
	s.push(1);
	while (3*s.top()+1 < n) {
		s.push(3 * s.top() + 1);
	}

	int m = s.size();
	printf("%d\n", m);

	for (int i = 0; i < m; i++) {
		insertionSort(A, n, s.top());
		if (i > 0) printf(" ");
		printf("%d", s.top());
		s.pop();
	}
	printf("\n%d\n",cnt);
}

int main() {
	int inputN;
	int A[1000000];

	scanf("%d", &inputN);
	for (int i = 0; i < inputN; i++) {
		scanf("%d", &A[i]);
	}
	shellSort(A, inputN);
	for (int i = 0; i < inputN; i++) {
		if (i > 0) printf("\n");
		printf("%d", A[i]);
	}
	return 0;
}