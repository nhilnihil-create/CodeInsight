#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
vector<vector<int>> g;
int n,m,s,t;
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int u,v;
	cin>>n>>m;
	g=vector<vector<int>>(3*n+1);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v+n);
		g[u+n].push_back(v+2*n);
		g[u+2*n].push_back(v);
	}
	cin>>s>>t;

	queue<int> q;
	int cur=0;q.push(s);
	vector<int> dist(3*n+1,1e9);
	vector<bool> vis(3*n+1);
	dist[s]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto u:g[x])
		{
			if(vis[u])continue;
			dist[u]=min(dist[u],dist[x]+1);
			q.push(u);vis[u]=1;
		}

	}

	if(dist[t]==1e9)cout<<-1;
	else cout<<dist[t]/3;


	

}