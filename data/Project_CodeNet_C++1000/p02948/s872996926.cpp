#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<vector<int>> jobs(m);
	for (ll i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if (m < a) continue;
		jobs[m - a].push_back(b);
	}
	int ans = 0;
	priority_queue<ll> pq;
	for (ll i = m - 1; i >= 0 ; i--) {		
		for (int b : jobs[i]) {
			pq.push(b);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << endl;
	return 0;
}