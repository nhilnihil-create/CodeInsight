#include <iostream>
using namespace std;
const int MOD = 1000000007;
const int MAX = 2000;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

long long inverse[MAX+1];
long long factorial[MAX+1];
long long factorial_inverse[MAX+1];

void calc(int n) {
	inverse[1] = 1;
	factorial[0] = factorial[1] = 1;
	factorial_inverse[0] = factorial_inverse[1] = 1;
	for (int i = 2; i <= n; i++) {
		inverse[i] = MOD - inverse[MOD%i] * (MOD/i) % MOD;
		factorial[i] = i * factorial[i-1] % MOD;
		factorial_inverse[i] = inverse[i] * factorial_inverse[i-1] % MOD;
	}
}

long long comb(long long n, long long k) {
	return factorial[n] * (factorial_inverse[k] * factorial_inverse[n-k] % MOD) % MOD;
}

long long rep_comb(long long n, long long k) {
	return comb(n + k - 1, k);
}

int main() {
	long long n, k;
	cin >> n >> k;
	calc(n);
	for (int i = 1; i <= k; i++) {
		long long ans;
		ans = rep_comb(i, k-i);
		if (n-k-(i-1) < 0) ans = 0;
		else ans = mod(ans * rep_comb(i+1, n-k-(i-1)));
		cout << ans << endl;
	}
	return 0;
}