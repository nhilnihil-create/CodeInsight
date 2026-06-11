#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
typedef pair<int,int> pi;

int n, vis[100005], out[100005], maxi;
vector<int> g[100005];
vector<pi> edges;
map<pi,int> ans;

void dfs(int x, int p, int col) {
	if (vis[x]) return;
	vis[x] = 1;
	int cnt = 1;
	for (auto i: g[x]) {
		if (i == p) continue;
		int now = (col + cnt) % maxi;
		++cnt;
		// cout << "x: " << x << " i:" << i << ' ' << " col: " << now << '\n';
		ans[pi(x, i)] = now;
		ans[pi(i, x)] = now;
		dfs(i, x, now);
	}
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;	
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++out[u], ++out[v];
		edges.pb(u, v);
	}
	for (int i = 1; i <= n; ++i) maxi = max(maxi, out[i]);
	dfs(1, 1, 0);
	cout << maxi << '\n';
	for (auto i: edges) {
		cout << ans[i] + 1<< '\n';
	}
	return 0;
}
