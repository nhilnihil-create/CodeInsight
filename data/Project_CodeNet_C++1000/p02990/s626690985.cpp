#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//二項係数
const int MAX = 2010000;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long C(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// 前処理 COMinit();
// 計算例 cout << COM(100000, 50000) << endl;

int main()
{
  COMinit();
  ll N,K; cin>>N>>K;
  if(N==K) {cout<<1<<endl; rep(i,K-1) cout<<0<<endl; return 0;}
  for(int i=1;i<=K;i++){
    ll T=2*C(N-K-1,i-1)+C(N-K-1,i);
    if(i>1) T+=C(N-K-1,i-2);
    T%=MOD;
    cout<<C(K-1,i-1)*T%MOD<<endl;
    //cout<<C(0,0)<<endl;
  }
  
  return 0;
}