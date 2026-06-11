#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//mod
const int mod = 1e9 + 7;
int powmod(int x, int y) { //x^y
	int rv = 1;
	for (; y > 0; y >>= 1, x = (long long) x * x % mod)
		if (y & 1)
			rv = (long long) rv * x % mod;
	return rv;
}
int inverce(int x) {
	return powmod(x, mod - 2);
}

//comb
const int factMax = 2e3;
int fact[factMax + 1];
void initializeFact() {
	fact[0] = 1;
	for (int i = 1; i <= factMax; i++)
		fact[i] = (long long) fact[i - 1] * i % mod;
}
int comb(int n, int k) {
	if (k < 0 || n - k < 0)
		return 0;
	int denom = (long long) fact[k] * fact[n - k] % mod;
	return (long long) fact[n] * inverce(denom) % mod;
}

int n;
ll ans = 0;

int main() {

	initializeFact();

	cin >> n;
	for (int l = 1; n - 3 * l >= 0; ++l) {
		ans += comb(n - 2 * l - 1, l - 1);
		ans %= mod;
	}
	cout << ans << endl;
}
