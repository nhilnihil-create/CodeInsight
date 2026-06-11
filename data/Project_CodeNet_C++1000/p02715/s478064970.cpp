#include <iostream>
#include <vector>
using namespace std;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long mod = 1000000007;
long long N, K, dp[100009];

int main() {
	cin >> N >> K;
	for (int i = K; i >= 1; i--) {
		dp[i] = modpow((K / i), N, mod);
		for (int j = i * 2; j <= K; j += i) { dp[i] -= dp[j]; dp[i] += mod; dp[i] %= mod; }
	}
	long long ans = 0;
	for (int i = 1; i <= K; i++) ans += 1LL * i * dp[i] % mod;
	cout << ans % mod << endl;
	return 0;
}