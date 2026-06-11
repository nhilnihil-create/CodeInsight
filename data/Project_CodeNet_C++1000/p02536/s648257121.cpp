#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

void dfs(int curr, vector<int> adj[], vector<bool>& vis) {
	vis[curr] = true;
	for (int node : adj[curr]) {
		if (!vis[node])
			dfs(node, adj, vis);
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n, m, a, b;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> vis(n + 1, false);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			count++;
			dfs(i, adj, vis);
		}
	}
	cout << count - 1 << endl;
	return 0;
}