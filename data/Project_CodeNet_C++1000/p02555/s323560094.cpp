#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
const int MAX = 510000;
//const int MOD = 998244353;
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

int main(){
    // 前処理
    COMinit();
    int S;
    cin >> S;
    int len = S/3; //配列の最大の長さ.
    ll ans = 0;
    for(int i=1;i<=len;i++){
        // 各配列の長さ分あらかじめ3を振っておき、
        // Sに足りない数numをi個の枠に自由に振り分ける
        // numをi個の枠に振り分けるのはnum個の〇とi-1個の仕切り|を並べる並べ方と同じ
        // (num+i-1)C(i-1)
        int num = S - i*3;
        ans += COM(num+i-1,i-1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}