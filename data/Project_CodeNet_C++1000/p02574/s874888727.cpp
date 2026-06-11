#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

const ll A = 1000005;




int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  vector<ll> c(A);
  rep(i,n){
    cin >> a.at(i);
    c.at(a.at(i))++;
  }
  bool pairwise = true;
  for(ll i=2;i<A;++i){
    ll cnt = 0;
    for(ll j=i;j<A;j+=i)
      cnt += c.at(j);
    if( cnt > 1 ) pairwise = false;
  }

  if( pairwise ){
    cout << "pairwise coprime" << endl;
    return 0;
  }

  ll g = 0;
  rep(i,n) g = __gcd(g,a.at(i));
  if( g == 1 )
    cout << "setwise coprime" << endl;
  else
    cout << "not coprime" << endl;
  return 0;
}