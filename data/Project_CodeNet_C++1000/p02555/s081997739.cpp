#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;

  const int MAX = 510000;
  
  ll fac[MAX], finv[MAX], inv[MAX];
  
  // テーブルを作る前処理
  //ここO(n)
  void COMinit() {
      fac[0] = fac[1] = 1;
      finv[0] = finv[1] = 1;
      inv[1] = 1;
      for (int i = 2; i < MAX; i++){
          fac[i] = fac[i - 1] * i % MOD;
          //すごいことしてO(1)で求めてる
          inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
          finv[i] = finv[i - 1] * inv[i] % MOD;
      }
  }
  
  // 二項係数計算
  ll COM(int n, int k){
      if (n < k) return 0;
      if (n < 0 || k < 0) return 0;
      return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
  }
  
int main() {
    COMinit();
    int s;
    cin >> s;
    ll cnt = 0;
    int keta=1;
    for(int keta=1;keta<=ll(s/3);keta++){
        ll remain = s-keta*3;
        cnt+=COM(keta-1+remain,remain);
        cnt %= MOD;
    }
    cout << cnt << endl;
    return 0;
}