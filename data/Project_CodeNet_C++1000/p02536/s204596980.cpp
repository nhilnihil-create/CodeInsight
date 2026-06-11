#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

void dfs(ll v, vector<vector<ll>>& adj, vector<bool>& vis)
{
    vis[v] = 1;
    for(auto u : adj[v])
    {
        if(vis[u]) continue;
        dfs(u,adj,vis);
    }
}

int main()
{
    ll n,m,i,j;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll cc = 0;
    vector<bool> vis(n+1,false);
    for(i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        cc++;
        dfs(i,adj,vis);
    }
    cout<<cc-1;
}