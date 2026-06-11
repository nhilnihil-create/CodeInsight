#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

int dp[100010][2];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = 2;
    dp[0][1] = 1;
    Rep(i, 1, n)
    {
        if (s[i] == '0')
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = (dp[i - 1][1] * 3) % mod;
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        else
        {
            dp[i][0] = (dp[i - 1][0] * 2) % mod;
            dp[i][1] = (dp[i - 1][1] * 3 + dp[i - 1][0]) % mod;
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
    }
    int ans = (dp[n - 1][0] + dp[n - 1][1]) % mod;
    cout << ans << endl;
}
