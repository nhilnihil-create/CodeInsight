#include <bits/stdc++.h>

using namespace std;

#define int			long long
#define endl		"\n"
#define ff			first
#define ss			second
#define mod			1000000007
#define inf			1e18
#define IOS			ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void dfs(int src, vector<vector<int>>& adj, vector<bool>& vis) {
	vis[src] = 1;

	for (int to : adj[src]) {
		if (!vis[to])
			dfs(to, adj, vis);
	}
}

int32_t main() {

	IOS;

	int n , m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<bool> vis(n);

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int cc = 0;

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i, adj, vis);
			cc++;
		}
	}

	cout << cc - 1;

	return 0;
}