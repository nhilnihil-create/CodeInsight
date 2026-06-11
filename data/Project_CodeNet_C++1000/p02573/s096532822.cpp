#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
vector<int>g[200001];
int vis[200001];
vector<int>comp[200001];
int x=0;
void dfs(int node)
{
    vis[node]=1;
    comp[x].push_back(node);
    for(auto i:g[node])
    {
        if(!vis[i])
            dfs(i);
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        vis[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
        x++;
    }
    int ans=0;
    for(int i=0;i<x;i++)
        ans=max(ans,(int)comp[i].size());
    cout<<ans<<endl;
}