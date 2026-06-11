#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

const int MAX = (int)1e6;
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
 long long COM(int n, int k){  //nCkの計算をする
     if (n < k) return 0;
     if (n < 0 || k < 0) return 0;
     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
 }

int main(){
  ll s;
  cin>>s;
  COMinit();
  ll ans(0);
  for(int i(1);i<=s;i++){
    ll nokori = s - 3*i;
    if (nokori < 0) break;
    ll tmp = COM(nokori+i-1, i-1);
    //cout << tmp << endl;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}

