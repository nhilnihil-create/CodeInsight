#include <iostream>
using namespace std;

void p(long A[], long n) {
	for (int i = 0; i < n; ++i) {
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

long insertionSort(long A[], long n, long g) {
	long cnt = 0;
	for (long i = g; i < n; ++i) {
		long v = A[i];
		long j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j -= g;
			++cnt;
		}
		A[j + g] = v;
	}
	return cnt;
}

const long gseries[] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573};

long shellSort(long A[], long n) {
	long *G = new long[n];
	long m = 0;
	for (; m < 11; ++m) {
		if (gseries[m] >= n) {
			break;
		}
	}
	for (long i = 0; i < m; ++i) {
		G[i] = gseries[m - 1 - i];
	}
	if (m == 0) {
		m = 1;
		G[0] = 1;
	}

	cout << m << endl;
	p(G, m);

	long cnt = 0;
	for (long i = 0; i < m; ++i)
		cnt += insertionSort(A, n, G[i]);

	delete[] G;
	return cnt;
}

int main() {
	
	long n;
	cin >> n;

	long *A = new long[n];
	for (long i = 0; i < n; ++i) cin >> A[i];

	cout << shellSort(A, n) << endl;
	for (long i = 0; i < n; ++i) cout << A[i] << endl;

	delete[] A;
	return 0;
}