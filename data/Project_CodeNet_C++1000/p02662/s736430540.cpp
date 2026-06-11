#include <bits/stdc++.h>

using namespace std;
const int N = 3e3 + 3, MOD = 998244353;
int a[N], dp[N];

void mod(int &a) {if (a >= MOD) a -= MOD;}
int mul(int a, int b) {return 1ll * a * b % MOD;}
int Pow(int a, int b) {
    int res = 1;
    for (; b; b>>=1, a = mul(a, a)) if (b&1) res = mul(res, a);
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, S; scanf("%d%d", &n, &S);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    dp[0] = Pow(2, n);
    int inv = Pow(2, MOD - 2);
    for (int i = 0; i < n; i++)
        for (int j = S; j >= a[i]; j--) dp[j] += mul(dp[j - a[i]], inv), mod(dp[j]);
    printf("%d\n", dp[S]);

    return 0;
}
