#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;





int main() 
{
  ll L,R; cin>>L>>R;
  if(R-L+1>=2019) {cout<<0<<endl; return 0;}
  vector<ll> vec(0);
  for(ll i=L;i<=R;i++)
  {
    vec.push_back(i%2019);
  }
  ll ans=10000;
  for(ll i=0;i<R-L+1;i++)
  {
    for(ll j=i+1;j<R-L+1;j++)
    {
      ans=min(ans,vec.at(i)*vec.at(j)%2019);
    }
  }
  cout<<ans<<endl;
  return 0;
}
