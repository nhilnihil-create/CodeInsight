#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int mod = 1e9 + 7;

ll fpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll inv(ll x) {
	return fpow(x, mod - 2);
}

ll C(ll n, ll m) {
	ll res = 1;
	ll mi = min(m, n - m);
	for (int i = 1; i <= mi; i++) {
		res = res * (n - i + 1) % mod * inv(i) % mod;
	}
	return res;
}

int main() {
	ll n, a, b; cin >> n >> a >> b;
	cout << (fpow(2, n) - C(n, a) - C(n, b) - 1 + mod + mod) % mod;
}