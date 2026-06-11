#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

//二項係数の計算前処理（KとNが10^7程度）
const int MAX = 510000;
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

signed main(){
  COMinit();
  int N, K;
  cin >> N >> K;

  int ans = 0;
  for( int i = 1; i <= K; i++ ){
    int blue = COM(K-1, i-1);
    int red = COM(N-K+1, i);
    int A = (blue*red)%MOD;
    cout << A << endl;
  }

}
