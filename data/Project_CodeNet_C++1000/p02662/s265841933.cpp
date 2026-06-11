#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 998244353;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

ll powmod(ll n, ll x)
{
    vector<ll> vll(32);
    vll[0] = n;
    FOR(i, 1, 32)
    {
        vll[i] = (vll[i - 1] * vll[i - 1]) % MOD;
    }
    ll ret = 1;
    int cnt = 0;
    while (x > 0) {
        if (x & 1) {
            ret = (ret * vll[cnt]) % MOD;
        }
        x >>= 1;
        cnt++;
    }
    return ret;
}

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> vi(n);
    REP(i, n)
    cin >> vi[i];
    vector<vector<int>> dp(n+1, vector<int>(s + 1, 0));
    dp[0][0] = 1;
    FOR(i, 1, n+1)
    {
        REP(j, s+1)
        {
            dp[i][j] = (dp[i][j] + ((dp[i - 1][j] * 2) % MOD)) % MOD;

            if (j + vi[i-1] <= s)
                dp[i][j + vi[i-1]] = (dp[i][j + vi[i-1]] + dp[i - 1][j]) % MOD;
        }
    }

    cout << dp[n][s] << endl;
}