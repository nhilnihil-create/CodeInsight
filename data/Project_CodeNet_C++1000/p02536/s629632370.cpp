# include<bits/stdc++.h>
# define ll long long
# define fo(i,n)for(int i=0;i<n;i++)
# define fo1(i,n)for(int i=1;i<=n;i++)
# define pb push_back
# define endl "\n"
# define mod 1000000007ll
# define pi  3.1415926535897932384626
using namespace std;

vector<vector<int>>adj(100005);
vector<int>vis(100005,0);
void dfs(int i)
{
  if(!vis[i])
  {
    vis[i]=1;
    for(auto v:adj[i])
    {
      dfs(v);
    }
  }
}
void solve()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      cnt++;
      dfs(i);
    }
  }
    cout<<cnt-1;
}
int main()
{
 # ifndef ONLINE_JUDGE
   freopen("input1.txt","r",stdin);
   freopen("output1.txt","w",stdout);
 #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    cout<<endl;
    return 0;
}