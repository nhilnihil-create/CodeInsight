#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000001];
int vis[1000001];
void dfs(int src,int &node)
{
    node++;
    vis[src]=1;
    for(int child:adj[src])
    {   
       
        if(vis[child]==0)
        {
            dfs(child,node);
        }
    }
}
int main()
{
    int n,m,count,ans=-1;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            int count=0;
            dfs(i,count);
            //cout<<count<<" ";
            ans=max(ans,count);
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}