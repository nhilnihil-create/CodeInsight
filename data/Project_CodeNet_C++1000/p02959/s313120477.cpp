#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N + 1);
	for (int n = 0; n < N + 1; ++n) {
		cin >> A[n];
	}
	vector<int>B(N);
	for (int n = 0; n < N ; ++n) {
		cin >> B[n];
	}
	long long ans = 0;
	for (int n = 0; n < N; ++n) {
		long long tmp = min(A[n],B[n]);
		A[n] -= tmp;
		B[n] -= tmp;
		ans += tmp;
		tmp = min(A[n+1],B[n]);
		A[n + 1] -= tmp;
		B[n] -= tmp;
		ans += tmp;
	}
	cout << ans <<endl;
	return 0;
}
