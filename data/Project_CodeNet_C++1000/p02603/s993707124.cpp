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

int main() {
  int N,a,c=0;
  cin >> N;
  vector<int> A(1,201);
  rep(i,N) {
    cin >> a;
    if (c>0 && A[c]==a) continue;
    else {
      A.push_back(a);
      c++;
    }
  }
  A.push_back(99);
  N=c+2;
  
  ll m=1000,s=0;
  rep2(i,1,c+1) {
    if ((A[i-1]<A[i]&&A[i]<A[i+1]) || (A[i-1]>A[i]&&A[i]>A[i+1])) {
      continue;
    }
    else if (A[i-1]<A[i]&&A[i]>A[i+1]) {
      m += s*A[i];
      s=0;
    }
    else {
      s += m/A[i];
      m -= m/A[i]*A[i];
    }
  }
  cout << m << endl;
}
