#include<iostream>
#include<cmath>
using namespace std;
void insertionSort(int*, int, int);
void shellSort(int*, int);
void write(int*, int,int*,int);
int cnt = 0;

int main() {
	int n, A[1000010];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	shellSort(A, n);
}

void insertionSort(int *A, int n, int g) {
	for (int i = g; i < n; i++) {
		int v = *(A + i);
		int j = i - g;
		while (j >= 0 && *(A + j) > v) {
			*(A + j + g) = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int *A, int n) {
	cnt = 0;
	int m = 0, G[110];
	G[0] = 1;
	int copy[1000010];
	for (int i = 0; i < n; i++) {
		copy[i] = A[i];
	}

	do {
		G[0] = 3 * G[0] + 1;
		m++;
	} while (G[0] <= n / 9);
	G[0] /= 3;
	for (int i = 1; i < m; i++) {
		G[i] = G[i - 1] / 3;
	}
	for (int i = 0; i < m; i++) {
		insertionSort(A, n, G[i]);
	}
	if(cnt < pow(n,1.5)) write(G, m, A, n);
	else {
		//cerr << "!!" << endl;
		cnt = 0;
		for (int i = m; i != -1; i--) {
			if (i == 0)G[0] = 3 * G[1] + 1;
			else G[i] = G[i - 1];
		}
		for (int i = 0; i <= m; i++) {
			insertionSort(copy, n, G[i]);
		}
		write(G, m+1, copy, n);
	}
}

void write(int *G, int m,int *A,int n) {
	cout << m << endl;
	for (int i = 0; i < m; i++) {
		cout << G[i];
		if (i == m - 1) cout << endl;
		else cout << " ";
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}

}