

#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


int main() {
  ll n;
  cin >> n;
  vector<P> v(n);
  rep(i,n){
    ll a1,b1;
    cin>>a1>>b1;
    v[i]=make_pair(b1,a1);
  }
  sort(v.begin(),v.end());
  ll t=0;
  rep(i,n){
    t+=v[i].second;
    if (t>v[i].first){
      cout<<"No";
      return 0;
    }
  }
  cout<<"Yes";
}
