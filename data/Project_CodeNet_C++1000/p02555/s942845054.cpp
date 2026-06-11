#include <bits/stdc++.h>
#define ll int
int const MOD = 1e9 + 7;
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;
ll sum;
ll cache[700][2001];
ll dp(int i, int s)
{
    if (s > sum)
        return 0;
    if (s == sum)
        return 1;
    ll &ans = cache[i][s];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int j = 3; j <= sum-s; j++)
        ans += dp(i + 1, s + j), ans %= MOD;
    return ans % MOD;
}
int32_t main()
{
    fastIO;
    memset(cache, -1, sizeof(cache));
    cin >> sum;
    ll ans = 0;
    for (int i = 3; i <= sum; i++)
        ans += dp(0, i), ans %= MOD;
    cout << ans;

    return 0;
}