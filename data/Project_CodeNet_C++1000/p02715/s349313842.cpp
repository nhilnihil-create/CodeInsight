#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long pow_mod(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int N, K;  cin >> N >> K;
    long long ans = 0;
    vector<long long> memo(K + 1);
    for (long long X = K; X >= 1; --X) {
        memo[X] = pow_mod(K / X, N) % MOD;
        for (int i = 2; i * X <= K; ++i) {
            memo[X] = (memo[X] - memo[i * X] + MOD * 2) % MOD;
        }
        ans = (ans + X * memo[X] % MOD) % MOD;
    }
    cout << ans << endl;
}
