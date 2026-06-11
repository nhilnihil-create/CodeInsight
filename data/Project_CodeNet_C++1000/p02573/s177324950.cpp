#include <bits/stdc++.h>

using namespace std;

void dfs(int curr, vector<vector<int>>& adj, unordered_set<int>& remaining) {

	remaining.erase(curr);

	for(auto i:adj[curr]) {
		
		if(remaining.count(i) == 1)
			dfs(i, adj, remaining);
	}
}

int main() {

	int n,m,u,v;
	cin>>n>>m;

	vector<vector<int>> adj(n+1);
	for(int i=1; i<=m; i++) {

		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_set<int> remaining;
	for(int i=1; i<=n; i++) remaining.insert(i);
	int ans = 0;

	for(int i=1; i<=n; i++) {

		if(remaining.count(i) == 0) continue;

		int before = remaining.size();

		dfs(i, adj, remaining);

		int after = remaining.size();

		ans = max(ans, before-after);
	}

	cout<<ans<<endl;

	return 0;
}