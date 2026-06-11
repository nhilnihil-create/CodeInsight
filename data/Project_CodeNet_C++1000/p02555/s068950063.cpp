#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
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
long long COM(long long n, long long k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    // 前処理
    COMinit();

    long long S;
    std::cin >> S;
    long long ans = 0LL;

    if (S<3LL)
        ans=0LL;
    else
    {
        ans=0LL;
        for(long long n=1LL; n < S/3LL+1LL; n++)
        {
            long long o = S-3LL*n;
            long long s= o+n-1;

            ans += COM(s,o);
            ans %= MOD;
        }
    }
    
    std::cout << ans << std::endl;

}