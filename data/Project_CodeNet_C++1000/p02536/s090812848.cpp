#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5+5;
vector<int> adj[mxN];
vector<bool> vis(mxN, false);
void dfs(int i) {
	if(!vis[i]) {
		vis[i] = true;
		for(auto v : adj[i])
			dfs(v);
	}
}
int main() {
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y, --x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans(-1);
	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans;
	return 0;
}
