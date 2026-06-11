#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p=1000000007;
ll bin(ll val,ll po)
{
	if(po==0)
		return 1;
	ll ans=1;
	if(po%2==1)
	{
		po-=1;
		ans=ans*val%p;
	}
	ll p1=bin(val,po/2);
	ans=ans*p1%p;
	ans=ans*p1%p;
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	    ll n,m;
	    cin>>n>>m;
	    ll s,t;
	    vector<ll>adj[3*n+1];
	    for(ll i=1;i<=m;i++)
	    {
	    	ll u,v;
	    	cin>>u>>v;
	    	adj[u].push_back(v+n);
	    	adj[u+n].push_back(v+2*n);
	    	adj[u+2*n].push_back(v);
	    }
	    ll dist[3*n+1];
	    memset(dist,-1,sizeof(dist));
	    cin>>s>>t;
	    dist[s]=0;
	    queue<ll>q;
	    q.push(s);
	    ll visited[3*n+1];
	    memset(visited,0,sizeof(visited));
	    visited[s]=1;
	    while(!(q.empty()))
	    {
	    	ll x=q.front();
	    	q.pop();
	    	for(ll j:adj[x])
	    	{
	    		if(visited[j]==0)
	    		{
	    			visited[j]=1;
	    			q.push(j);
	    			dist[j]=dist[x]+1;
	    		}
	    	}
	    }
	    if(dist[t]==-1)
	    	cout<<"-1";
	    else
	    	cout<<dist[t]/3;
}