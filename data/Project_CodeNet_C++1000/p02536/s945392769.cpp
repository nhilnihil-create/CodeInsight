#include <bits/stdc++.h>
#define int long long
using namespace std;

const int nax = 1e5 + 1;
vector<int> adj[nax];
vector<bool> visited(nax, false);

void dfs (int x) {
	if (!visited[x]) {
		visited[x] = true;
		for (auto u : adj[x]) {
			dfs (u);
		}
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, x, y;
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		adj[x].push_back (y);
		adj[y].push_back (x);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			ans++;
			dfs (i);
		}
	}
	
	cout << ans - 1;
	
	return 0;
} 
