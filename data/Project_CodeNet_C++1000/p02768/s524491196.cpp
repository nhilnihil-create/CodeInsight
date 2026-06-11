#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
const int MAX = 2*100000;

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
	long long fact_n = n;
	for (long long i = n-1; i >= n-k+1; i--) fact_n = mod(fact_n*i);
	return mod(fact_n * factorial_inverse[k]);
}

long long pow_mod(long long a, long long n) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = (res * a) % MOD;
		n >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	calc(max(a, b));
	ll ans = mod(pow_mod(2, n) - 1 - comb(n, a) - comb(n, b));
	cout << ans << endl;
	return 0;
}