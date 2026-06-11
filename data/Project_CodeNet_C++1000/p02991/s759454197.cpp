#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
const int mxn=1e5+3,INF=1e18;
int n,m;
vector<int> g[mxn];
int vis[mxn][3];
int s,t;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
       // g[v].push_back(u);
    }
    cin>>s>>t;
   // for (int i=1;i<=n;i++) vis[i][0]=vis[i][1]=vis[i][2]=-1;
    queue<ar<int,2>> q;
    q.push({s,0});
    vis[s][0]=0;
    while(!q.empty())
    {
        int u=q.front()[0],time=q.front()[1];
        q.pop();
        for (int v : g[u])
        if (!vis[v][(time+1)%3])
        {
            vis[v][(time+1)%3]=vis[u][time]+1;
            q.push({v,(time+1)%3});
        }
    }
    if (vis[t][0]) cout<<vis[t][0]/3;
    else cout<<-1;
}
