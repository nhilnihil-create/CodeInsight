#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7,n;

map<ll,ll> mp;

void dfs(vector<ll> v[],ll idx,ll parent)
{

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
    ll arr[n];for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,greater<ll>());
    ll ans=arr[0];
    for(int i=2;i<n;i++)
      ans+=arr[i/2];
    cout<<ans;
}