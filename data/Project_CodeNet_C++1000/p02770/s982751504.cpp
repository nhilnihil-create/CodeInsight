#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long K, Q;
long long D[1 << 18];

long long solve(long long N, long long X, long long M) {
	long long S = X, ans = N - 1;
	for (int i = 0; i < K; i++) {
		long long V = (N + K - i - 2LL) / K;
		long long T1 = (D[i + 1] % M);
		S += V * T1;
		if (T1 == 0) ans -= V;
	}
	long long D1 = (X / M);
	long long D2 = (S / M);
	return ans - (D2 - D1);
}

int main() {
	cin >> K >> Q;
	for (int i = 1; i <= K; i++) cin >> D[i];

	for (int i = 1; i <= Q; i++) {
		long long A, B, C;
		cin >> A >> B >> C;
		cout << solve(A, B, C) << endl;
	}
	return 0;
}