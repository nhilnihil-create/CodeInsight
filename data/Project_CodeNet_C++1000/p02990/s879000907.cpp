#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

const int max_fac = 5 * 1e5;
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
  int n, k;
  cin >> n >> k;

  ComInit();
  long long ans = 0;
  for(int i = 1; i <= k; i++){
    ans = 0;
    int need = i - 1;
    int room = 2 + i - 1;
    int space = k - 1;
    int red = n - k - need;
    ans = Comb(space, need);
    ans %= MOD;
    ans *= Comb(room - 1 + red, red);
    ans %= MOD;
    cout << ans << endl;
  }

  return 0;
}