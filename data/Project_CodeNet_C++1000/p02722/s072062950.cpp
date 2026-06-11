#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  ll n;cin>>n;
  ll i;
  vector<ll> ls(1,n);
  ls.emplace_back(n-1);
  for(i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
      ls.emplace_back(i);
      ls.emplace_back(n/i);
    }
  }
  for(i=2;i*i<=n-1;i++)
  {
    if((n-1)%i==0)
    {
      ls.emplace_back(i);
      ls.emplace_back((n-1)/i);
    }
  }
  sort(all(ls));
  ll ans=0;
  rep(i,ls.size())
  {
    if(ls[i]<2||ls[i]>n)continue;
    if(i>0&&ls[i]==ls[i-1])continue;
    ll left=n;
    while(left%ls[i]==0)left/=ls[i];
    if(left%ls[i]==1)ans++;
  }
  cout<<ans<<endl;
}
