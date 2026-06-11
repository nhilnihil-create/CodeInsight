#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

// 二項係数ライブラリ---------------------------------------------------------------------------------------//
const ll MAX_COM = 1000007;
ll fac[MAX_COM], finv[MAX_COM], inv[MAX_COM];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1ll;
    finv[0] = finv[1] = 1ll;
    inv[1] = 1ll;
    for (int i = 2; i < MAX_COM; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = (finv[i - 1] * inv[i]) % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] % MOD * finv[k] % MOD * finv[n - k] % MOD;
}
// 二項係数ライブラリここまで-----------------------------------------------------------------------------------//


int X, Y;

ll solve() {
    COMinit();
    if((X+Y) % 3 != 0) return 0;
    else {
        int n = (X+Y) / 3;
        int k = X - n;
        return COM(n, k);
    }
}
int main(){
    cin >> X >> Y;
    printf("%lld\n", solve());
    return 0;
}