#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n;
  cin>>n;
  vector<ll> a(n);
  ll r=-1,g=-1,b=-1;
  ll ans=1;
  for (ll i = 0; i < n; ++i)
  {
    ll a;
    cin>>a;
    ll cnt=0;
    cnt+=(r==a-1)? 1:0;
    cnt+=(g==a-1)? 1:0;
    cnt+=(b==a-1)? 1:0;
    ans*=cnt;
    ans%=mod;
    if(r==a-1) r=a;
    else if(g==a-1) g=a;
    else if(b==a-1) b=a;
    else 
    {
      cout<<0<<endl;
      return 0;
    }
  }
  cout<<ans<<endl;
}