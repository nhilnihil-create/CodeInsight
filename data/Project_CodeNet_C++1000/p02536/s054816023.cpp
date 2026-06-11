#include <bits/stdc++.h>
using namespace std;
vector< int > adj[100005];
bool vis[100005];
int cc=0;
void dfs(int v)
{
  vis[v]=1;
  for(auto u:adj[v])
  {
    if(!vis[u])
      dfs(u);
  }
}
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      cc++;
      dfs(i);
    }
  }
  cout<<cc-1;
  return 0;
}
