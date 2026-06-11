#include <bits/stdc++.h>
using namespace std;

#define MAXN 500*1000

map<pair<int, int>, int> id;

vector<int> g[MAXN], topo;
int color[MAXN], dp[MAXN];

bool dfs(int u) {
	color[u] = 1;
	
	for(int v : g[u]) {
		if(color[v] == 1) {
			return false;
		} else if(color[v] == 0) {
			if(!dfs(v)) {
				return false;
			}
		}
	}
	
	color[u] = 2;
	topo.push_back(u);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int t = 0;
	for(int i = 0; i < n; i++) {
		vector<int> nodes;
		for(int j = 0; j < n-1; j++) {
			int u = i+1, v;
			cin >> v;
			if(u > v) swap(u, v);
			pair<int, int> p = {u, v};
			if(id.count(p) == 0) {
				id[p] = t++;
			}
			nodes.push_back(id[p]);
		}
		for(int j = 1; j < (int) nodes.size(); j++) {
			g[nodes[j-1]].push_back(nodes[j]);
		}
	}
	
	for(int i = 0; i < t; i++) {
		if(color[i] == 0) {
			if(!dfs(i)) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	int ans = 0;
	for(int u : topo) {
		dp[u] = 1;
		for(int v : g[u]) {
			dp[u] = max(dp[u], dp[v] + 1);
		}
		ans = max(ans, dp[u]);
	}
	
	cout << ans << endl;
}
