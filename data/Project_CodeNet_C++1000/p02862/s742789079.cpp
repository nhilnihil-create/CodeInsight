#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

ll power(ll b, ll p, ll m) {
	if (p == 0)
		return 1;

	if (p == 1)
		return b;

	if (p % 2 == 0) {
		ll a = power(b, p/2, m);
		return (a * a) % m;
	}

	return (b * power(b, p-1, m)) % MOD;
}

ll mul(ll a, ll b) {
	return (a * b) % MOD;
}

ll factorial(ll n) {
	ll f = 1;

	for (int i = 1; i <= n; i++) {
		f = mul(f, i);
	}

	return f;
}

ll choose(ll n, ll r) {
	ll c = factorial(n);

	c = (c * power(factorial(r), MOD-2, MOD)) % MOD;
	c = (c * power(factorial(n-r), MOD-2, MOD)) % MOD;

	return c;
}

int main() {
	ll x, y;

	cin >> x >> y;

	if ((x+y) % 3) {
		cout << 0 << "\n";
		return 0;
	}

	ll n = (2*y - x) / 3;
	ll m = (2*x - y) / 3;

	if (n < 0 || m < 0) {
		cout << 0 << "\n";
		return 0;
	}

	cout << choose(n+m, m) << "\n";

	return 0;
}