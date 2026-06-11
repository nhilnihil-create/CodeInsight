
//Totka hai dosto
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int mod=1e9+7;
const int N=1e5+6;
vector<int> adj[N];
int fact[N];
int ans;
int n,k;
void dfs(int node, int par)
{
	int color=k-1;
	if(par!=0)color--;
	for(auto u:adj[node])
	{
		if(u==par)continue;
		if(color<=0)
		{
			ans=0;return;
		}
		ans=(ans*color)%mod;
		color--;
		dfs(u,node);
	}
}
int32_t main()
{
	int u,v;
	cin>>n>>k;
	ans=k;
	
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0);
	cout<<ans;
	
	
}