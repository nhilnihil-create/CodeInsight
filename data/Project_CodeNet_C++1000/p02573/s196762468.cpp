#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7; 
vector<int> adj[200005];
bool vis[200005];
int dfs(int node){
	int c=1;
	vis[node]=true;
	for(auto i:adj[node]){
		if(!vis[i])
		c+=dfs(i);
	}
	return c;
}
int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(vis, false, sizeof(vis));
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
		ans=max(ans,dfs(i));
		}
	}
	cout<<ans;
}