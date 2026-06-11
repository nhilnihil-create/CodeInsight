#include <bits/stdc++.h>
	
using namespace std;
using ll = long long;
using ld = long double;

const int mxn = 2e5;
vector<int> adj[mxn];
vector<bool> vis(mxn, 1);
vector<int> ans(mxn, 0), acc(mxn, 0);

void dfs(int v){
	vis[v] = 0;
	ans[v] += acc[v];
	for(int u : adj[v]){
		if(vis[u]){
			acc[u] += acc[v];
			dfs(u);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; cin >> n >> q;
	for(int i = 0, a, b; i < n - 1; ++i){
		cin >> a >> b; --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0, a, b; i < q; ++i){
		cin >> a >> b; --a;
		acc[a] += b;
	}
	dfs(0);
	for(int i = 0; i < n; ++i){
		if(i) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}