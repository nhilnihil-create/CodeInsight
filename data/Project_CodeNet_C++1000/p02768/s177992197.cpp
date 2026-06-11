#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000000;
const int MOD = 1000000007;

long long finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    long long res = 1;
    for (int i = n; i >= n - k + 1; i--){
        res = res * i % MOD;
    }
    return res * finv[k] % MOD;
}

// a^n % m
long long modpow(long long a, long long n, long long m){
    long long res = 1;
    while(n > 0) {
        if(n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

void solve() {
    COMinit();
    int n, a, b;
    cin >> n >> a >> b;
    long long ans;
    ans = (modpow(2, n, MOD) - 1 - COM(n, a) - COM(n, b)) % MOD;
    ans = (ans + 2 * MOD) % MOD;
    cout << ans << endl;
}
int main() {
    solve();
    return 0;
}