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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, h[310];

    unordered_map<int, int> mp;
    unordered_map<int, int> pm;

    set<int> st;
    st.insert(0);

    cin >> n >> k;
    REP(i, n)
    {
        cin >> h[i];
        st.insert(h[i]);
    }

    int mpCnt = 0;
    for (int i : st)
    {
        mp[mpCnt] = i;
        pm[i] = mpCnt;
        mpCnt++;
    }

    ll dp[310][310][310];

    memset(dp, -1, sizeof(dp));

    dp[0][k][pm[h[0]]] = h[0];

    if (k > 0)
        dp[0][k - 1][pm[0]] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l < mpCnt; l++)
            {
                if (dp[i][j][l] == -1)
                    continue;

                ll val = dp[i][j][l] + max(0, h[i + 1] - mp[l]);

                if (dp[i + 1][j][pm[h[i + 1]]] == -1 || val < dp[i + 1][j][pm[h[i + 1]]])
                    dp[i + 1][j][pm[h[i + 1]]] = val;

                if (j > 0 && (dp[i + 1][j - 1][l] == -1 || dp[i][j][l] < dp[i + 1][j - 1][l]))
                    dp[i + 1][j - 1][l] = dp[i][j][l];
            }
        }
    }

    ll res = 1e18;

    for (int i = 0; i < mpCnt; i++)
        for (int j = 0; j <= k; j++)
        {
            if (dp[n - 1][j][i] != -1)
                res = min(res, dp[n - 1][j][i]);
        }

    cout << res << endl;

    return 0;
}