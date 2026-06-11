#include <bits/stdc++.h>
using namespace std;

// nCk の和について
// 引用資料：https://mathtrain.jp/nikoubekijo

////// a^n mod を計算する、a^(2^k) mod の積で求める、 O(n) から O(log(n)) の短縮が見込まれる
long modpow(long base, long exponent, long mod) {
    long power = 1;
    while (exponent > 0) {
        if (exponent & 1){
            power = power * base % mod;
        }
        base = base * base % mod;
        exponent >>= 1;
    }
    return power;
}

////// 二項係数の求め方
// 引用資料：https://drken1215.hatenablog.com/entry/2018/06/08/210000
// COMinit() : O(n), COM(n, k) : O(1)
const int MOD = 1000000007;
const int MAX = 200002;

long factorial[MAX], finv[MAX], inv[MAX]; 

// テーブルを作る前処理
void COMinit() {
    factorial[0] = factorial[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        factorial[i] = factorial[i - 1] * i % MOD;      // factorial[] : a! (mod MOD)
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;    // inv[] : a^-1     (mod MOD) 
        finv[i] = finv[i - 1] * inv[i] % MOD;           // finv[] : (a!)^-1 (mod MOD) 
    }
}

// 二項係数計算
long COM(int n, int k){
    long ans = 1;
    for (int i = 0; i < k; i++){
        ans = (ans * (n - i) % MOD) * inv[i+1] % MOD;
    }
    return ans;
}

int main(void){
    // 入力
    int n, a, b;
    cin >> n >> a >> b;

    COMinit();
    long combiSum = modpow(2, n, MOD) - 1;
    cout <<  ( combiSum - COM(n, a) - COM(n, b) + 2*MOD) % MOD << endl;

    return 0;
}
