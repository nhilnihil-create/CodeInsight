
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


int main() {
  ll x, k, d;
  cin>>x>>k>>d;
  ll x1=abs(x);
  ll a=x1/d;
  ll ans;
  if(a>k)ans=x1-(k*d);
  else{
    ll a1=x1-(a*d);
    ll a2=x1-((a+1)*d);
    if((k-a)%2==0)ans=abs(a1);
    else ans=abs(a2);
  }
cout<<ans;
}
