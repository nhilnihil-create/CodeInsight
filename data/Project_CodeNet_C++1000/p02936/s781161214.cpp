#include <bits/stdc++.h>
	
using namespace std;
using ll = long long;
using ld = long double;

const int mxn = 2e5;
vector<int> adj[mxn];
vector<bool> vis(mxn, 1);
vector<int> ans(mxn, 0), acc(mxn, 0);

void bfs(int w){
	vis[w] = 0;
	ans[w] += acc[w];
	queue<int> q;
	q.push(w);
	while(q.size()){
		int v = q.front();
		q.pop();
		for(int u : adj[v]){
			if(vis[u]){
				vis[u] = 0;
				acc[u] += acc[v];
				ans[u] += acc[u];
				q.push(u);
			}
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
	bfs(0);
	for(int i = 0; i < n; ++i){
		if(i) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}