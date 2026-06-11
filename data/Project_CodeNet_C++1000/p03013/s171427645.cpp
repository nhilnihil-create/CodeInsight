#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, m; cin >> n >> m;
	vector<bool> isBroken(n + 1, false);
	for (ll i = 0; i < m; i++) {
		ll a; cin >> a;
		isBroken[a] = true;
	}
	const ll mod = 1000000007;
	vector<ll> dp(n + 1, 0);
	dp[0] = 1;
	if (!isBroken[1]) dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!isBroken[i - 1]) {
			dp[i] += dp[i - 1];
			dp[i] %= mod;
		}
		if (!isBroken[i - 2]) {
			dp[i] += dp[i - 2];
			dp[i] %= mod;
		}	
	}
	cout << dp[n] << endl;
	return 0;
}