#include <iostream>
using namespace std;
typedef long long ll;
#define MOD1 1000000007
const int MAX = 510000;
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
#define nHr(n,r) COM((n)+(r)-1,(r))
int main(){
  COMinit();
  ll n,k,i,j,result=1;
  cin >> n >> k;
  for(i=1;i<=k;i++){
    result = COM(n-k+1,i);
    result *= COM(k-1,i-1);
    result %= MOD1;
    cout << result << endl;
  }
  return 0;
}