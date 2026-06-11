#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int s[N];
int dp[N];
int n,k;

int pw(int n, int k)
{
    if (!k) return 1;
    int res = pw(n, k >> 1);
    res = res * res % mod;
    if (k & 1) return n * res % mod;
    return res;
}

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
}

void sub(int &a, int b)
{
    a -= b;
    if (a < 0) a += mod;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        add(s[i], s[i - 1]);
        dp[i] = (pw(i, n) - s[i] + mod) % mod;
        for (int j = 2; i * j <= k; j++)
        {
            add(s[i * j], dp[i]);
            if ((i + 1) * j <= k) sub(s[(i + 1) * j], dp[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        add(ans, i * dp[k / i] % mod);
    }
    cout << ans;
    return 0;
}
