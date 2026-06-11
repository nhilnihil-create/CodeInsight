#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<long long> vals(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> vals[i + 1];
	}

	vector<int> adj[n + 1];

	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (!adj[i].size()) {
			ans++;
			continue;	
		}
		bool ok = 1;
		for (int j = 0; j < adj[i].size(); j++) {
			if (vals[adj[i][j]] >= vals[i]) {
				ok = 0;
				break;
			}
		}
		if (ok) ans++;
	}

	cout << ans;
}
