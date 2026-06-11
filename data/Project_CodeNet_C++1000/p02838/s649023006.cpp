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
  vector<ll> A(N); rep(i,N) cin>>A[i];
  
  vector<ll> p(60,0);
  rep(i,N){
    rep(j,60){
      if(A[i]&(1LL<<j)) p[j]++;
    }
  }
  
  //rep(i,60) cout<<p[i]<<endl;
  
  ll ans=0;
  rep(i,60){
    ans+=p[i]*(N-p[i])%MOD*mod_pow(2,i)%MOD;
    ans%=MOD;
  }
  
  cout<<ans<<endl;
  return 0;
}
