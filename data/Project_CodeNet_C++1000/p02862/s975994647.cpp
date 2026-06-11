#include <bits/stdc++.h>
using namespace std;

////// 二項係数の求め方
// 引用資料：https://drken1215.hatenablog.com/entry/2018/06/08/210000
// COMinit() : O(n), COM(n, k) : O(1)
const int MOD = 1000000007;
const int MAX = 1000000;//510000;

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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return factorial[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int x, y;
    cin >> x >> y;

    COMinit();
    int n = (x+y)/3;
    int k = (x+y)/6 - abs(((x-y)/2));
    if ((x+y)%3 == 0){
        cout << COM(n, k) << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
