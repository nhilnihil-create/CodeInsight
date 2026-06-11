#include<cstdio>

const int MOD = 998244353;
int n, s, a[3000];
int dp[3001];

int po(int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y & 1) ans = static_cast<long>(ans) * x % MOD;
        x = static_cast<long>(x) * x % MOD;
        y >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int inv2 = po(2, MOD - 2);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = s; j >= a[i]; j--) {
            dp[j] = (dp[j] + static_cast<long>(dp[j - a[i]]) * inv2 % MOD) % MOD;
        }
    }

    printf("%ld\n", static_cast<long>(dp[s]) * po(2, n) % MOD);
    return 0;
}
