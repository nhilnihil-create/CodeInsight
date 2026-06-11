#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

P f( ll x ){
  ll head,tail;
  tail = x%10;
  while( x ){
    head = x;
    x /= 10;
  }
  return make_pair(head,tail);
}

int main(){
  ll n;cin >> n;
  map<P,ll> m;
  for(ll i=1;i<=n;++i){
    if( i%10 == 0 ) continue;
    P p = f(i);
    m[p]++;
  }
  ll ans = 0;
  for(auto mp : m ){
    if( mp.second == 0 ) continue;
    P p = mp.first;
    P rp = make_pair(p.second,p.first);
    ans += m[rp]*m[p];
  }
  cout << ans << endl;
  return 0;
}