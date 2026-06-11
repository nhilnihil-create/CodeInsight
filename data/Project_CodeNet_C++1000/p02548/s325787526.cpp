#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n;
  cin>>n;
  ll ans=0;
  for (ll i = 1; i < n; ++i)
  {
    ans+=n/i;
    if (n%i==0) ans--;
  }
  cout<<ans<<endl;
}