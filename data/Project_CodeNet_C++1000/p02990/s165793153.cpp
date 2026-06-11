#include <iostream>
typedef long long ll;
const int MOD = 1e9 + 7;
using namespace std;

ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

ll cmb(ll n, ll a) {
	if (n - a < a) return cmb(n, n - a);

	ll res = 1;
	for (ll i = n; n - a + 1 <= i; i--) { res *= i;  res %= MOD; }
	for (ll i = 2; i <= a; i++) { res = res * modinv(i, MOD) % MOD; }

	return res;
}

int main() {
	ll n, k;
	cin >> n >> k;
	for (ll i = 1; i <= k; i++) {
		if (n - k + 1 >= i)
			cout << cmb(n - k + 1, i) * cmb(k - 1, i - 1) % MOD << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
