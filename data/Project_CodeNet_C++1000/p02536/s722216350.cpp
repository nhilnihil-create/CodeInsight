#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<bool>vis;
void dfs(int s){
	vis[s] = 1;
	for(int nie : g[s]){
		if(!vis[nie]){
			dfs(nie);
		}
	}
}
int main(){
	int n, m; cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int u, v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	vis.resize(n+1, 0);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans++;
			dfs(i);
		}
	}
	cout<<ans-1<<endl;
}
