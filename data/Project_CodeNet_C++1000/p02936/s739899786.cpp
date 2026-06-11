#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=1e5+3;
int n,q;
vector<vector<int>> g;
vector<int> wt;
void dfs(int node, int par=-1)
{
	if(par!=-1)wt[node]+=wt[par];
	for(auto u:g[node])
	{
		if(u==par)continue;
		dfs(u,node);
	}
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>q;
	g=vector<vector<int>>(n);
	wt=vector<int>(n);
	int a,b;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	while(q--)
	{
		cin>>a>>b;
		wt[a-1]+=b;
	}

	dfs(0);

	for(int i=0;i<n;i++)cout<<wt[i]<<" ";

	

	
	
	
}