#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

const ll MOD = 1000000007;

int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);

  ll ans = 0;
  rep(i,60){
    ll x = 0;
    // 与数字のi桁目が1である個数を求める
    rep(j,n) if( a.at(j) >> i & 1 ) ++x;
    // i桁目が1の個数(=x)と0の個数(=n-x)の積
    // xor では 0 ^ 1 = 1 なので
    // i桁目の0と1の組み合わせの総数が、
    // 答えのi桁目になる。
    ll now = x*(n-x)%MOD;
    // 桁を合わせる
    rep(j,i) now = now*2%MOD;
    ans += now;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
