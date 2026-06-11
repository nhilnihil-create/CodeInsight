#include <bits/stdc++.h>
using namespace std;
constexpr int64_t MOD = 1e9 + 7;


int64_t modpow(int64_t x, int64_t n){
    int64_t res = 1;
    for(int64_t i = n; i > 0; i >>= 1){
        if(i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int64_t comb(int64_t n, int64_t k){
    if(n - k < k) k = n - k;
    int64_t ch = 1, pa = 1;
    for(int64_t i = n; i > n - k; i--){
        ch = ch * i % MOD;
    }
    for(int64_t i = k; i > 0; i--){
        pa = pa * i % MOD;
    }

    return ch * modpow(pa, MOD - 2) % MOD;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int64_t ans = modpow(2, n) - 1;
    ans = ((ans - comb(n, a) + MOD) % MOD - comb(n, b) + MOD) % MOD;
    cout << ans << endl;
    return 0;
}