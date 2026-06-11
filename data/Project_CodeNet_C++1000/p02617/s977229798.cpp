#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7,n;

map<ll,ll> mp;

void dfs(vector<ll> v[],ll idx,ll parent)
{
  if(idx==1) mp[1]=n;
  else
  {
    if(parent>idx) mp[idx]=idx*(parent-idx);
    else mp[idx]=(idx-parent)*(n-idx+1);
  }
  for(auto a:v[idx])
  {
    if(a!=parent) dfs(v,a,idx);
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;cin>>n;
    vector<ll> v[n+1];
    for(int i=0;i<n-1;i++)
    {
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    dfs(v,1,1);
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=mp[i];
      cout<<ans;
}