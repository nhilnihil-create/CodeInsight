#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, m; cin >> n >> m;
	vector<vector<ll>> jobs(m);
	for (ll i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		if (m < a) continue;
		jobs[m - a].push_back(b);
	}
	ll ans = 0;
	priority_queue<ll> q;
	for (ll date = m - 1; date >= 0; date--) {
		for (ll i = 0; i < jobs[date].size(); i++) {
			q.push(jobs[date][i]);
		}
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}	
	cout << ans << endl;
	return 0;
}