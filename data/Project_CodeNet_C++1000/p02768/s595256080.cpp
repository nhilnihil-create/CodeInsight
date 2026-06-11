#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = 1000000007;

ll mod = 1000000007;

ll modpow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

ll modcmb(int n, int r) {
	ll ans = 1;
	rep(i, r) {
		ans *= (n - i) * modpow(i + 1, mod - 2) % mod;
		ans %= mod;
	}
	return ans;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	ll all_sum = modpow(2, n);
	ll exclusion = (modcmb(n, a) + modcmb(n, b)) % mod;
	ll ans = all_sum - exclusion;
	ans = (ans + mod) % mod;
	cout << ans - 1 << endl;
	return 0;
}