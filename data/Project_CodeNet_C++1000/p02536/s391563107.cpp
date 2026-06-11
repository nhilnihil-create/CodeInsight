#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100000];
vector<bool>visited(100000, false);
void dfs(int s)
{
  visited[s] = true;
  for(int u:adj[s])
    if(!visited[u])
      dfs(u);
}
int main()
{
  int i, n, m;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
	int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  for(i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      ans++;
      dfs(i);
    }
  }
  ans--;
  cout<<ans;
  cout<<"\n";
  return 0;
}