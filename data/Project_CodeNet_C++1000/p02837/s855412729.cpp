#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main(){
  ll n;cin >> n;
  vector< vector<ll> > g(n,vector<ll>(n));
  rep(i,n) rep(j,n) g.at(i).at(j) = -1;

  rep(i,n){
    ll a;cin >> a;
    rep(j,a){
      ll x,y;cin >> x >> y;
      g.at(i).at(x-1) = y;//i番目の人は、x-1番目の人をyだと証言する
    }
  }
  //g.at(i).at(j)が
  // -1 -> 証言なし、何もしない
  // 0 ->　不親切な人だという証言
  //1 ->　正直者だという証言

  int ans = 0;

  //0...0 ~ 1...1　の全ての状態の場合を列挙
  for(ll i=0;i<(1<<n);++i){
    vector<ll> d(n);// 今の状態を配列に保存
    rep(j,n) if( i>>j & 1 ) d.at(j) = 1;
    
    bool ok = true;//矛盾がなければtrue
    rep(j,n){
      if( d.at(j) == 1 ){//j番目の人が正直者だという状態の時
        rep(k,n){
          if( g.at(j).at(k) == -1 ) continue;
          if( g.at(j).at(k) != d.at(k) ) ok = false;
        }
      }
    }
    if( ok ) ans = max(ans,__builtin_popcount(i));
  }

  cout << ans << endl;

  return 0;
}