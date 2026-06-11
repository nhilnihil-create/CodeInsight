#include<iostream>
#include<algorithm>
using namespace std;
static const int nMAX = 1000000;
static const int mMAX = 100;
int cnt = 0;

int insertionSort(int* A, int n, int g) {
	for (int i = g; i < n; i++) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
	return 0;
}

int shellSort(int* A, int n) {
	int m = 0;
	int g = 0;
	while (g <= n) {
		g = g * 3 + 1;
		m++;
	}
	g = g / 3;
	m = m - 1;
	int* G = new int[mMAX];
	for (int i = 0; i < m; i++) {
		G[i] = g;
		g = g / 3;
	}
	cout << m << endl;
	for (int i = 0; i < m-1; i++) {
		cout << G[i]<<' ';
	}
	cout << G[m-1] << endl;
	
	for (int i = 0; i < m; i++) {
		insertionSort(A, n, G[i]);
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	int* A = new int[nMAX];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	shellSort(A, n);
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}
	
	return 0;
}
