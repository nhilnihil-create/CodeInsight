#include<bits/stdc++.h> 
using namespace std; 
#define deb(x) cout <<"\n"<< (#x) << " = " << (x) << "\n"
const long long  INF = 1e18;
const long long mod=1e9+7 ;
void inputoutput()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	    
}


vector<int> adj[200500];
vector<int> vis(200500);

void dfs(int v,int& ans)
{
	++ans;
	vis[v]=true;
	for(auto u : adj[v])
	{
		if(!vis[u])
			dfs(u,ans);
	}
}



void solve()
{
		// dfs implementation in undirected graph
	int n ;   // no. of vertices
	cin>>n ;
	int e;    // no. of edjes
	cin>>e;
	for(int i=0 ; i<e ; ++i)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int sol=INT_MIN ;
	for(int i=1 ; i<=n ; ++i)
	{
		if(!vis[i])
		{
			int ans=0;
			dfs(i,ans);
			sol=max(sol,ans);
		}
	}

	cout<<sol<<"\n";


}

int32_t main()
{ 
	inputoutput() ;
	solve();


	return 0;
}
