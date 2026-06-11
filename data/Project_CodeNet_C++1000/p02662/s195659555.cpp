#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005;
const int mod = 998244353;

int n, s;
int a[Maxn];
int dp[Maxn];

int main()
{
    scanf("%d %d", &n, &s);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        for (int j = s; j >= 0; j--) if (dp[j]) {
            if (j + a <= s)
                dp[j + a] = (dp[j + a] + dp[j]) % mod;
            dp[j] = 2ll * dp[j] % mod;
        }
    }
    printf("%d\n", dp[s]);
    return 0;
}
