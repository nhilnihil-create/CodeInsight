#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// 二項係数を用いる
const int MAX = 1000100;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

  // テーブルを作る前処理
  /* facが普通の階乗を求めている。invが逆数を求めている。finvが逆数の階乗を求めている。*/
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

  // 二項係数を計算する
long long COM(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int N, K;

int main() {
    cin >> N >> K;
    int blue = K; int red = N-K;
    COMinit();
    for(int i = 1; i <= K; ++i) {
        long long ans = 1;
        int blueblock = i;
        if(red >= blueblock-1) {
            // 青が絶対に隣合わない並べ方
            int cred = red+1;
            ans *= COM(cred, blueblock);
            ans %= MOD;

            // あとは青の並べ方を計算
            int wall = blueblock-1;
            int cwall = blue-1;
            ans *= COM(cwall, wall);
            ans %= MOD;
        }else ans = 0;
        cout << ans << endl;
    }
}