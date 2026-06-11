#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const long long MAX = 1000000;
const long long MOD = 1000000007;


long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        //そのまま計算すると負の値になるのでMODを足す
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
/*
long long COM(long long n, long long k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
*/

long long COM2(long long n, long long k) {
    long long t1 = 1;
    long long t2 = 1;
    for(long long i=n;i>=n-k+1;i--) {
        t1 = (t1 * i) % MOD;
    }
    return (t1 * finv[k]) % MOD;
}

long long fast_pow(long long n, long long k) {
    if(k==0) return 1;
    if(k%2 == 0) {
        return fast_pow(n*n % MOD, k/2);
    } else {
        return (fast_pow(n, k-1) * n) % MOD;
    }
}

int main() {
    COMinit();
    long long int n, a, b;
    cin >> n >> a >> b;

    long long ans = (fast_pow(2, n) - COM2(n, a)+MOD) % MOD;
    ans = (ans - COM2(n, b) + MOD) % MOD;
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;
}