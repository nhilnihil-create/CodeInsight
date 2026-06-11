#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}"<<endl;
  return o;
}

//逆元　a/b の modをとるとき -> a*modinv(b)%mod
long long modinv(long long a, long long m = 1e9+7) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m; 
  if (u < 0) u += m;
  return u;
}
ll const mod = 1e9+7;

// combination
const int MAX = 510000;
const ll MOD = 1000000007;
 
long long fac[MAX], finv[MAX], inv[MAX];
 
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// べき乗
ll modpow(ll x, ll n) {
    x = x%MOD;
    if(n==0) return 1;  //再帰の終了条件

    else if(n%2==1) {
        return (x*modpow(x, n-1))%MOD;  //nが奇数ならnを1ずらす
    }
    else return modpow((x*x)%MOD, n/2)%MOD;  //nが偶数ならnが半分になる
}

int main() {
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  vector<int> c(N+1,0);
  rep(i,N) {
    auto t = A[i];
    c[max(0,i-t)]++;
    c[min(N-1,i+t)+1]--;
  }
  
  rep(i,K) {
    int now = 0;
    vector<int> ta(N,0),tc(N+1,0);
    rep(j,N) {
      now += c[j];
      ta[j] = now;
      auto t = ta[j];
      tc[max(0,j-t)]++;
      tc[min(N-1,j+t)+1]--; 
    }
    if (A==ta) break;
    A = ta;
    c = tc;
  }
  for (auto i:A) cout << i << ' ';
  cout << endl;
}
