#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e9;

int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> dp((1 << n), INF);
	dp[0] = 0;
	for (ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		ll key = 0;
		for (ll j = 0; j < b; ++j) {
			ll c;
			cin >> c;
			key |= 1 << (c - 1);
		}
		for (ll j = 0; j < (1 << n); ++j) {
			dp[j | key] = min(dp[j | key], dp[j] + a);
		}
	}
	if (dp.back() == INF)cout << -1 << endl;
	else cout << dp.back() << endl;
}
