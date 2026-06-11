#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

vector<int> adj[100005];
bool vis[100005];

void dfs(int node)
{
    vis[node]=1;
    for(int i:adj[node])
    {
        if(!vis[i])
        dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        int n,m,x,y,i;
        cin>>n>>m;
        while(m--)
        {
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        x=0;
        for(i=1;i<=n;++i)
        {
            if(!vis[i])
            x++,dfs(i);
        }
        cout<<max(0,x-1);
    }
}