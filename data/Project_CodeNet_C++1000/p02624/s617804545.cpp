
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;


int main() {
  ll n;
  cin>>n;
  ll ans=0;
  for(int i=1;i<=n;i++){
    ll y=n/i;
    ll s=y*(1+y)*i/2;
    ans+=s;
  }

cout<<ans;
}
