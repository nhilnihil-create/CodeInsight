#include<bits/stdc++.h>
using namespace std;
int c=0;
bool comp(int a,int b)
{
    return a>b;
}
void dfs(int node,vector<int>adj[],bool vis[])
{
   vis[node]=true;
   for(int u:adj[node])
   {
       if(vis[u]==false)
       {
           c++;
           dfs(u,adj,vis);
       }
   }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool vis[n+1];
    memset(vis,0,sizeof(vis));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            c=1;
            dfs(i,adj,vis);
            ans=max(ans,c);
        }
    }
    cout<<ans<<endl;

}