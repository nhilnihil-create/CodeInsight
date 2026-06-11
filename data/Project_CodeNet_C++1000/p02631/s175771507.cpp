#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

const ll MOD = 1000000007;

int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  ll total;
  rep(i,n){
    cin >> a.at(i);
    if( i == 0 ) total = a.at(i);
    else total ^= a.at(i);
  }
  vector<ll> ans(n);
  rep(i,n) ans.at(i) = total ^ a.at(i);
  rep(i,n){
    cout << ans.at(i);
    if( i != n-1 ) cout << " ";
    else cout << endl;
  }

  return 0;
}
