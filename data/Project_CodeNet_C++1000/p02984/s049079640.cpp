#include "bits/stdc++.h"
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	int sum = 0;
	for (int n = 0;n<N;++n) {
		cin >> A[n];
		sum += A[n];
	}
	vector<int>B(N);
	B[0] = sum;
	for (int n = 1;2*n-1 < N;++n) {
		B[0] -= 2*A[2 * n - 1];
	}
	for (int n = 1; n < N; ++n) {
		B[n] = 2 * A[n-1] - B[n - 1];
	}
	for (int n = 0; n < N; ++n) {
		if (0 != n) {
			cout << " ";
		}
		cout << B[n];
	}
	

	
	return 0;
}