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


ll mypow(ll X, ll n) {  // 繰り返し２乗法　計算量log(n)
    if(n == 0) return 1ll;
    ll Y = mypow(X, n/2);
    if(n % 2 == 1) return X * Y % MOD * Y % MOD;
    else return Y * Y % MOD;
}

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

// Nが大きいときの二項係数計算
// N = 10^9, k = 2*10^5まで使える
const ll MAX_COM_NB = 200010;
vector<ll> COM_NB(MAX_COM_NB);
void COM_NBinit(int N) {
    // COMinit();
    COM_NB[0] = 1ll;
    rp(i, 1, MAX_COM_NB) {
        COM_NB[i] = COM_NB[i-1] * (N+1-i) % MOD * inv[i] % MOD;
    }
}

// 二項係数ライブラリここまで-----------------------------------------------------------------------------------//




int main() {
    int N, a, b;
    cin >> N >> a >> b;
    ll res = mypow(2, N) + MOD - 1;
    res %= MOD;
    COMinit();
    COM_NBinit(N);
    res = (res + MOD - COM_NB[a]) % MOD;
    res = (res + MOD - COM_NB[b]) % MOD;
    cout << res << endl;
    return 0;
}