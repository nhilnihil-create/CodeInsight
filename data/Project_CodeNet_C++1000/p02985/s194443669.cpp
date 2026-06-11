#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>adj[100100];
ll visited[100100];
ll p=1000000007;
ll ans=1;
ll n,k;
ll dfs(ll x)
{
	visited[x]=1;
	ll cur=2;
	for(ll i=1;i<adj[x].size();i++)
	{
		ans=ans*(k-cur)%p;
		cur++;
	}
	for(ll i:adj[x])
	{
		if(visited[i]==0)
		{
			dfs(i);
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	    cin>>n>>k;
	    ll u,v;
	    for(ll i=1;i<n;i++)
	    {
	    	cin>>u>>v;
	    	adj[u].push_back(v);
	    	adj[v].push_back(u);
	    }
	    ll start;
	    for(ll i=1;i<=n;i++)
	    {
	    	if(adj[i].size()==1)
	    	{
	    		start=i;
	    		break;
	    	}
	    }
	    if(n==1)
	    {
	    	cout<<k;
	    	return 0;
	    }
	    visited[start]=1;
	    ans=k;
	    ans=ans*(k-1)%p;
	    visited[adj[start][0]]=1;
	    dfs(adj[start][0]);
	    cout<<ans;
}