#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
vector<int>adj[100001];
int vis[100001]={false};
void dfs(int i){
	vis[i]=true;
	for(auto p : adj[i]){
		if(!vis[p])
		 dfs(p);}}
int main(){IOS;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!vis[i])
			ans++;
			dfs(i);}
			cout<<ans-1<<endl;}