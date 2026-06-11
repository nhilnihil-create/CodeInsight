#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main(){
  ll n;cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n){
    ll x,y;cin >> x >> y;
    a.at(i) = x+y;
    b.at(i) = x-y;
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  ll ans = max(a.back()-a.front(),b.back()-b.front());
  cout << ans << endl;
  return 0;
}
