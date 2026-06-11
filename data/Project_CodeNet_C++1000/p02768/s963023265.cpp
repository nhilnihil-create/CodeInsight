#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
vector<ll> com;
const ll maxk = 2e5 + 1;

ll modpow(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

long long extGCD(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x); // 再帰的に解く
	y -= a / b * x;
	return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long Mod(long long a, long long m) {
	return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
	long long x, y;
	extGCD(a, m, x, y);
	return Mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	com.push_back(1);
	for (ll i = 1; i < maxk; ++i) {
		com.push_back(com[i - 1] * (n - i + 1));
		com[i] %= mod;
		com[i] *= modinv(i, mod);
		com[i] %= mod;
	}
	ll ans = modpow(2, n);
	ans -= com[a] + com[b] + 1;
	ans += 10 * mod;
	ans %= mod;
	cout << ans << endl;
}
