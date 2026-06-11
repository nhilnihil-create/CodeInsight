#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for (int i = (n); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dp[1001][1001];

int main()
{
    string s, t;
    cin >> s >> t;

    rep(i, 1001) dp[i][0] = i;
    rep(j, 1001) dp[0][j] = j;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i] == t[j])
                dp[i + 1][j + 1] = min({dp[i][j], dp[i + 1][j] + 1, dp[i][j + 1] + 1});
            else
                dp[i + 1][j + 1] = min({dp[i][j] + 1, dp[i + 1][j] + 1, dp[i][j + 1] + 1});
        }
    }

    OP(dp[s.size()][t.size()]);

    return 0;
}
