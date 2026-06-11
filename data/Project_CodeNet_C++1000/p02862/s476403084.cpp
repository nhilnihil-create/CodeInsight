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

const int max_fac = 2 * 1e6;
long long fac[max_fac], finv[max_fac], inv[max_fac];
void ComInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < max_fac; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long Comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  ComInit();
  int x,y;
  cin >> x >> y;

  int cnt_1 = 0;
  long long ans = 0;
  bool flag = 0;
  while(!flag){
    long long cur_x = cnt_1;
    long long cur_y = 2 * cnt_1;
    if(cur_x > x || cur_y > y) break;
    long long res_x = x - cur_x;
    long long res_y = y - cur_y;
    // cout << "now (x,y) = " << cur_x << ", " << cur_y << endl;
    // cout << "rest (x,y) = " << res_x << ", " << res_y << endl;
    if(res_y * 2 == res_x){
      // can be reached
      // cout << "can be reached " << endl;
      int cnt_2 = res_y;
      // cout << "cnt1 = " << cnt_1 << ", cnt2 = " << cnt_2 << endl;
      ans += Comb(cnt_1+cnt_2, cnt_1);
      ans %= MOD;
    }
    cnt_1 ++;
  }
  cout << ans << endl;


  return 0;
}