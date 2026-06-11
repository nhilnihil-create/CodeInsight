#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

//mod逆元を使ったnCkの計算(速)
const int64_t MAX = 3000010;
const int64_t MOD = 1000000007;
 
int64_t fac[MAX], finv[MAX], inv[MAX];
 
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
int64_t COM(int64_t n, int64_t k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
//繰り返し二乗法
int64_t powmod(int64_t x, int64_t n) { 
  int64_t ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans = ans * x;
      ans %= MOD;
    }
    x = x * x;//一周する度にx, x^2, x^4, x^8となる
    x %= MOD;
    n >>= 1; //桁をずらす n = n >> 1
  }
  return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int64_t n,k;
    cin >> n >> k;
    COMinit();
    rep(i,k){
        int64_t x=COM(n-k+1,i+1);
        int64_t y=COM(k-1,i);
        int64_t ans = (x%MOD)*(y%MOD);
        ans=ans%MOD;
        cout << ans << "\n";
    }
    return 0;
}   