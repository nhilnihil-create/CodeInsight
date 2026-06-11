#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

long long modpow(long long a, long long n, long long mod){
  long long res = 1;
  while(n > 0){
    //nを２進数に分解してビットの立っているところだけ掛け算していく。
    if (n &  1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// a inverse (mod m)
// a^(-1) = a^(p-2) (mod p)
long long modinv(long long a, long long mod){
  return modpow(a, mod-2, mod);
}

long long Comb(long long n, long long k){
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  // return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
  long long ans = 1;
  for(long long i = 0; i < k; i++){
    ans = ans * (n - i) % MOD;
    ans = ans * modinv(k - i, MOD) % MOD;
  }
  return ans;
}

int main(){
  int n,a,b;
  cin >> n >> a >> b;

  long long ans = 1;
  ans = modpow(2, n, MOD) - 1;

  long long bya = Comb(n, a);
  long long byb = Comb(n, b);
  // cout << ans << "," << bya << "," << byb << endl;
  ans -= (bya + byb);
  ans %= MOD;
  if(ans < 0) ans = (ans + MOD) % MOD;
  cout << ans << endl;
  

  return 0;
}