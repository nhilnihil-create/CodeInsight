#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v[200001];
bool vis[200001];
int l1;
void dfs(int x)
{
  if(vis[x]) return ;
  vis[x]=1;l1++;
  for(int i=0;i<v[x].size();i++)
  {
    if(!vis[v[x][i]])
     dfs(v[x][i]);
  }
}
int32_t main()
{
  int t,n,i,j,k,m,l=0,max1=0;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
    cin>>j>>k;
    v[j].push_back(k);
    v[k].push_back(j);
  }
  memset(vis,0,sizeof(vis));
  for(i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      l1=0;
      dfs(i);
      max1=max(max1,l1);
    }
  }
  cout<<max1;
}