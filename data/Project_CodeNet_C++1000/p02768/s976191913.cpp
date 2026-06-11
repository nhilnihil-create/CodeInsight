#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
 
const int MAX = 1000000;
const int MOD = 1000000007;
 
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
  int n,a,b;
  cin >> n>>a>>b;
  long c=modpow(2,n,MOD);
  long ca=1;
  rep(i,a){
    ca=ca*(n-i)%MOD*modpow(a-i,MOD-2,MOD)%MOD;
  }
  long cb=1;
  rep(i,b){
    cb=cb*(n-i)%MOD*modpow(b-i,MOD-2,MOD)%MOD;
  }
  c=(c-ca-cb+2*MOD-1)%MOD;
  
    cout<<c<<endl;
}