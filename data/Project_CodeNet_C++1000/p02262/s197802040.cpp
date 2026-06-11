#include<iostream>

using namespace std;

void print(long A[], long n) {
	for (long i = 0; i < n; i++) {
		cout << A[i] << endl;
	}
}

long insertionSort(long A[], long n, long g) {
	long cnt = 0;
	for (long i = g; i < n; i++) {
		long v = A[i];
		long j = i - g;
		for (; j >= 0 && A[j] > v; j -= g) {
			A[j + g] = A[j];
			cnt++;
		}
		A[j + g] = v;
	}
	return cnt;
}

void shellSort(long A[], long n) {
	long cnt = 0;
	long m;
	long G[13];
	G[0] = 1;
	for (m = 0; G[m] <= n; m++) {
		G[m + 1] = ((G[m] * 2 + 1) * 3 - 1) / 2;
	}
	cout << m << endl;
	for (long i = m - 1; i >= 0; i--) {
		cnt += insertionSort(A, n, G[i]);
		if  (i != m - 1) {
			cout << " ";
		}
		cout << G[i];
	}
	cout << endl << cnt << endl;
}

int main() {
	long n;
	cin >> n;
	long A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	shellSort(A, n);
	print(A, n);

	return 0;

}