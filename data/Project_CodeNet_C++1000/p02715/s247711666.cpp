#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = (int)1e9 + 7;
ll power(ll b, ll e) {
	ll r = 1;
	while(e) {
		if(e % 2 == 1) {
			r *= b;
			r %= MOD;
		}
		e >>= 1;
		b *= b;
		b %= MOD;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ll> dp(k + 1, 0);
	ll ans = 0;
	for(int i = k; i >= 1; --i) {
		dp[i] = power(k / i, n);
		for(int j = 2 * i; j <= k; j += i) {
			dp[i] -= dp[j];
			if(dp[i] < 0) dp[i] += MOD;
		}
		// cout << dp[i] << " ";
		ans += i * dp[i];
		ans %= MOD;
	}
	cout << ans;
	return 0;
}