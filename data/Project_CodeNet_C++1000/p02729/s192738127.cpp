#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

// 考える整数の最大値
const int MAX = 200;
// 今回採用する大きい素数を適当に設定
const int MOD = 1000000007;

// メモを保管する場所
ll fact[MAX], inv_fact[MAX], inv[MAX];

// メモを計算する
void init() {
    // 初期値設定と1はじまりインデックスに直す
    fact[0] = 1;
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    inv_fact[0] = 1;
    inv_fact[1] = 1;
    // メモの計算
    repi(i, 2, MAX){
        // 階乗
        fact[i] = fact[i - 1] * i % MOD;
        // 逆元
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        // 逆元の階乗
        inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
    }
}

// 二項係数の実体
ll nCk(int n, int k) {
    ll x = fact[n]; // n!の計算
    ll y = inv_fact[n-k]; // (n-k)!の計算
    ll z = inv_fact[k]; // k!の計算
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return x * ((y * z) % MOD) % MOD;
}


int main(){
  init();
  int N, M;
  cin >> N >> M;
  cout << nCk(N, 2) + nCk(M, 2) << endl;
}