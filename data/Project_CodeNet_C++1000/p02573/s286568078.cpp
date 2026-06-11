#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define dou  double 
#define endl "\n"

const int MOD=1e9+7;

vector<int> adj[200005];
int vis[200005];

int dfs(int src,int cnt)
{
	vis[src]=1;
	for(int i=0;i<adj[src].size();i++)
	{
		int x = adj[src][i];
		if(!vis[x])
			cnt = dfs(x,cnt+1);
	}
	return cnt;
}

void solve()
{
	int n,m,i,x,y,mx=INT_MIN;
	cin >> n >> m;
	for(i=0;i<m;i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			x = dfs(i,1);
			mx = max(mx,x);
		}
	}
	cout << mx << endl;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	solve();
}