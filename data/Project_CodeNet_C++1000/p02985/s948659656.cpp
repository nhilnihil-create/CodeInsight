#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
const int N=1000000007;
int p[100005];
int np[100005];
bool vis[100005];
vector<vector<int>>adj;
void dfs(int v, int pa){
	p[v]=pa;
	for(auto u:adj[v]){
		if(u==pa){
			continue;
		}
		dfs(u, v);
	}
}

main() {
	int n, k;
	cin>>n>>k;
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int ans=k;
	dfs(1, 1);
	queue<int>q;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		vis[node]=1;
		for(auto u:adj[node]){
			if(vis[u]==1){
				continue;
			}
			int num;
			if(p[p[u]]==p[u]){
				num=1;
			}
			else{
				num=2;
			}
			num+=np[node];
			np[node]++;
			if(num>=k){
				cout<<0;
				return 0;
			}
			ans=(ans*(k-num))%N;
			q.push(u);
		}
	}
	cout<<ans;
	return 0;
}