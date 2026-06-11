#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  vector<ll> c(1000005,0);
  rep(i,n){
    cin >> a.at(i);
    c.at(a.at(i))++;
  }

  // pairwise の判定
  bool pairwise = true;
  for(ll i=2;i<1000005;++i){
    ll cnt = 0;
    for(ll j=i;j<1000005;j+=i){
      cnt += c.at(j);
    }
    if( cnt > 1 ){
      pairwise = false;
    }
  }

  // setwise の判定
  bool setwise = true;
  ll gcd_all = 0;
  rep(i,n) gcd_all = __gcd(gcd_all,a.at(i));
  if( gcd_all != 1 ) setwise = false;

  // 出力
  if( pairwise )
    cout << "pairwise coprime" << endl;
  else if( setwise )
    cout << "setwise coprime" << endl;
  else
    cout << "not coprime" << endl;

  return 0;
}