#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<bool> visited(100005, false);
vector<int> adj[100005];

void dfs(int st) {
	if (!visited[st])
	{
		visited[st] = true;
		for (auto x : adj[st]) {
			dfs(x);
		}
	}
}
int32_t main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int total = 0;
	for (int i = 1; i <= n; i++) {

		if (!visited[i]) {
			total += 1;
			dfs(i);
		}
	}
	cout << total - 1 << endl;
}