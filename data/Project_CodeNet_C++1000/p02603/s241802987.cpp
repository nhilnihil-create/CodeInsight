#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 105;

LL dp[N];

int a[N];

int n;

void solve() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        scanf("%d", &a[i]);

    dp[0] = 1000;
    for (int i=1; i<=n; ++i) {
        dp[i] = max(dp[i], dp[i-1]);
        for (int j=1; j<i; ++j) {
            dp[i] = max(dp[i], dp[j] % a[j] + (LL)(dp[j] / a[j]) * a[i]);
        }
    }
    printf("%lld\n", dp[n]);
}

int main() {
    solve();

    return 0;
}