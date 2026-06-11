#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const int maxn = 500050;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const ll linf = 7e18;
ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

ll gcd(ll x, ll y)
{
    if (x % y == 0)
        return y;
    return gcd(y, x % y);
}

int dp[3005][3005], a[3005], b[3005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, i, j, k, x, y;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j] * 2 % mod;
            if (j >= a[i])
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
