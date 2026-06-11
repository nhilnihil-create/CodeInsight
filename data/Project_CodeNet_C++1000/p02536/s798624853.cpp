#include <bits/stdc++.h>
using namespace std;

#define int long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define all(x) begin(x),end(x)

int mod = 1e9+7;
int inf = 4e18;
const int N = 5e5+5;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int child)
{
	if(vis[child])
	return;
	vis[child] = true;
	for(auto &it:adj[child])
	dfs(it);
}		
signed main()
{
    flash
    int tt = 1;
    //cin>>tt;
    while(tt--)
    {
		int n;
		cin>>n;
		int m;
		cin>>m;
		adj.resize(n+1);
		vis.resize(n+1);
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		int ans = 0;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				++ans;
				dfs(i);
			}
		}
		cout<<ans-1;
    }
    return 0;
}
