#include<bits/stdc++.h>
using namespace std;
#define int long long
 
vector<int>adj_list[200005];

void dfs(int u,vector<int>&flag,int *kitna)
{
  *kitna=*kitna+1;
  flag[u]=1;
  for(auto v:adj_list[u])
  {
    if(flag[v]==-1)
    {
      dfs(v,flag,kitna);
    }
  }
}
 
int32_t main()
{
  vector<int>arr;
  int n;int m;cin>>n>>m;
  vector<int>flag(n+1,-1);
  for(int i=1;i<=m;i++)
  {
    int u;int v;cin>>u>>v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    if(flag[i]==-1)
    {
      int kitna=0;
      dfs(i,flag,&kitna);
      arr.push_back(kitna);
    }
  }
  int ans=*max_element(arr.begin(),arr.end());
  cout<<ans<<endl;
}