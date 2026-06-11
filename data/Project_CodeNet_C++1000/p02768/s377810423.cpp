#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a

ll mod_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main()
{
  ll n,a,b; cin>>n>>a>>b;
  
  //nCaの前計算
  ll S=1;
  rep(i,a) S=S*(n-i)%MOD; 
  rep(i,a) S=S*mod_pow(i+1,MOD-2)%MOD;
  
  //nCbの前計算
  ll T=1;
  rep(i,b) T=T*(n-i)%MOD; 
  rep(i,b) T=T*mod_pow(i+1,MOD-2)%MOD;
  
  ll ans=(mod_pow(2,n)-S-T-1)%MOD;
  while(ans<0) ans+=MOD;
  
  cout<<ans<<endl;
  return 0;
}