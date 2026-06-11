#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 1000000007;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b / (1LL << i)) % 2LL == 1LL) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long N, K, dp[1 << 18];

int main() {
	cin >> N >> K;
	for (int i = K; i >= 1; i--) {
		dp[i] = modpow(K / i, N, mod);
		for (int j = 2 * i; j <= K; j += i) dp[i] -= dp[j];
		dp[i] = (dp[i] + mod * mod) % mod;
	}

	long long r = 0;
	for (int i = 1; i <= K; i++) r += 1LL * i * dp[i] % mod;
	cout << r % mod << endl;
	return 0;
}