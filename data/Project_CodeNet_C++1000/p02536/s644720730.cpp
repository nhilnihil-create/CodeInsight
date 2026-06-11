#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int> >&adj,vector<bool> &vis,int i)
{
  if(vis[i]==true)
    return;
  vis[i]=true;
  for(int x:adj[i])
  {
    if(!vis[x])
      dfs(adj,vis,x);
  }
}
int main()
{
  int n,m,a,b,ans=0;
  cin>>n>>m;
  vector<bool> vis(n+1,false);
  vector<vector<int> >adj(n+1);
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i]==false)
    {
      ans++;
      dfs(adj,vis,i);
    }
  }
  cout<<ans-1;
  return 0;
}
