#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)998244353, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, s, i, j, a[3003];
    ll dp[3003][3003] = {};

    scanf("%d%d", &n, &s);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    dp[0][0] = 1;
    for (i = 0; i < n; i++) for (j = 0; j <= s; j++) {
        dp[i + 1][j] = dp[i][j] * 2 % mod;
        if (j >= a[i]) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - a[i]]) % mod;
    }

    printf("%lld\n", dp[n][s]);

    return 0;
}