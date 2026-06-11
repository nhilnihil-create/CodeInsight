#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	--x, --y;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; ++i) {
		adj[i].push_back(i + 1);
		adj[i + 1].push_back(i);
	}
	adj[x].push_back(y);
	adj[y].push_back(x);
	vector<int> cnt(n);
	for (int i = 0; i < n; ++i) {
		// bfs
		vector<int> dist(n, (int) 1e9 + 5);
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v: adj[u]) {
				if (dist[u] + 1 < dist[v]) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		for (int j = i + 1; j < n; ++j) {
			cnt[dist[j]]++;
		}
	}
	for (int i = 1; i < n; ++i) {
		cout << cnt[i] << '\n';
	}
	return 0;
}