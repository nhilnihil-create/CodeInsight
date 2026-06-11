#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

void dfs(ll u,vector<ll> g[],vector<bool> &vis,ll &count)
{
   vis[u]=1;
   count++;
   for(auto x:g[u])
   {
      if(vis[x]==0)
      {
         dfs(x,g,vis,count);
      }
   }
}
int main() 
{
   ll n,m;
   cin>>n>>m;
   vector<ll> g[n];
   for(ll i=0;i<m;i++)
   {
      ll x,y;
      cin>>x>>y;
      x--;y--;
      g[x].push_back(y);
      g[y].push_back(x);
   }
   vector<bool> vis(n,false);
   ll ans=INT_MIN;
   for(ll i=0;i<n;i++)
   {
      if(vis[i]==0)
      {
         ll count=0;
         dfs(i,g,vis,count);
         ans=max(ans,count);
      }
   }
   cout<<ans<<endl;
   return 0;
}