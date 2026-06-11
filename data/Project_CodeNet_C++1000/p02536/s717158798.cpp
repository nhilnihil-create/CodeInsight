#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>vis;
void dfs(int v)
{
 vis[v]=true;
 for(auto it : adj[v])
 {
  if(!vis[it])
   dfs(it);
 }
}
int main()
{
 int n,m;
 int ans=0;
 cin>>n>>m;
 adj.resize(n+1);
 vis.resize(n+1,false);
 set<int>s;
 for(int i=0;i<m;i++)
 {
  int a,b;
  cin>>a>>b;
  adj[a].push_back(b);
  adj[b].push_back(a);
 }
  for(int i=1;i<=n;i++)
  {
   if(!vis[i])
   {
    dfs(i);
    ans++;
   }
  }
cout<<ans-1;
}