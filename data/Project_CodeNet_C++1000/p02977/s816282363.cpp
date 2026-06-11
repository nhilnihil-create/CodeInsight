#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, M;
	cin >> N;
	M = 1LL << (long long)(log2(N));
	if (N == M) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if (N % 2 == 1) {
		for (int i = 2; i <= N; i += 2) {
			cout << i << " " << i + 1 << endl;
			cout << i + 1 << " " << 1 << endl;
			cout << 1 << " " << i + N << endl;
			cout << i + N << " " << i + 1 + N << endl;
		}
		cout << 1 + N << " " << 2 << endl;
	}
	else {
		cout << N << " " << M + 1 << endl;
		cout << M << " " << M + 1 << endl;
		cout << M + 1 << " " << 1 << endl;
		cout << 1 << " " << M + N << endl;
		cout << N - M + N << " " << N + N << endl;
		cout << N + N << " " << M + 1 + N << endl;
		cout << M + 1 + N << " " << 1 + N << endl;
		for (int i = 2; i <= N - 2; i += 2) {
			if (i == M) continue;
			cout << i << " " << i + 1 << endl;
			cout << i + 1 << " " << 1 << endl;
			cout << 1 << " " << i + N << endl;
			cout << i + N << " " << i + 1 + N << endl;
		}
	}
}