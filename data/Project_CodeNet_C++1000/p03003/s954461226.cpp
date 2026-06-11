#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

ll dp[2010][2010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s[2123], t[2123];
    cin >> n >> m;
    REP(i, n)
    cin >> s[i + 1];
    REP(i, m)
    cin >> t[i + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            if (i > 0)
                (dp[i][j] += dp[i - 1][j]) %= MOD;
            if (j > 0)
                (dp[i][j] += dp[i][j - 1]) %= MOD;

            if (i > 0 && j > 0 && s[i] != t[j])
                (dp[i][j] += MOD - dp[i - 1][j - 1]) %= MOD;
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}