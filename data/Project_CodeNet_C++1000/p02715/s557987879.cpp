#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int sz = 1e5 + 1;

ll n, k;
ll dp[sz];

ll bpow(ll x, ll p) {
	if (p == 0)
		return 1;
	if (p % 2)
		return (bpow(x, p - 1) * x) % mod;
	else {
		ll b = bpow(x, p / 2);
		return (b * b) % mod;
	}
}

void solve() {
	cin >> n >> k;
	dp[k] = 1;
	for (int i = k - 1; i >= 1; i--) {
		int j = 2;
		ll cnt = k / i;
		dp[i] = bpow(cnt, n);
		while (i * j <= k) {
			dp[i] -= dp[i * j++];
			dp[i] += mod;
			dp[i] %= mod;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= k; i++) {
		ans += (dp[i] * i) % mod;
		ans %= mod;
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		cout << endl;
	}
}
