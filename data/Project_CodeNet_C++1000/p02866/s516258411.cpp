#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
//const ll MOD=1000000007;
const ll MOD=998244353;
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
  ll N; cin>>N;
  vector<ll> D(N); rep(i,N) cin>>D[i];
  if(D[0]!=0) {cout<<0<<endl; return 0;}
  
  //最大距離の点求める
  ll max_D=-INF;
  rep(i,N) chmax(max_D,D[i]);
  
  //街道
  vector<ll> vec(max_D+1,0); rep(i,N) vec[D[i]]++;
  if(vec[0]!=1) {cout<<0<<endl; return 0;}
  
  ll ans=1; rep(i,max_D) ans=ans*mod_pow(vec[i],vec[i+1])%MOD;
  
  cout<<ans<<endl;
  
  return 0;
}
