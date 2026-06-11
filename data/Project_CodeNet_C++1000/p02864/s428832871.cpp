#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }

    vector<int> a(n);
    copy(h.begin(), h.end(), a.begin());
    a.push_back(0);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    const int64_t M = 1'000'000'000L * n;
    vector<vector<vector<int64_t>>> dp(n + 1, vector<vector<int64_t>>(k + 1, vector<int64_t>(a.size())));
    irep(i, n) irep(j, k)
    {
        if (i == 0) {
            rep(l, a.size())
            {
                dp[i][j][l] = j == 0 && l == 0 ? 0 : M;
            }
        } else {
            rep(l, a.size())
            {
                dp[i][j][l] = M;
                if (a[l] == h[i - 1]) {
                    rep(l2, a.size())
                    {
                        dp[i][j][l] = min(dp[i][j][l], dp[i - 1][j][l2] + max(0L, (int64_t)a[l] - a[l2]));
                    }
                }
            }
            if (j > 0) {
                int64_t x = M;
                rep(l, a.size())
                {
                    x = min(x, dp[i - 1][j - 1][l] - a[l]);
                    dp[i][j][l] = min(dp[i][j][l], x + a[l]);
                }

                int64_t y = M;
                rrep(l, a.size())
                {
                    y = min(y, dp[i - 1][j - 1][l]);
                    dp[i][j][l] = min(dp[i][j][l], y);
                }
            }
        }
    }

    int64_t result = M;
    irep(j, k) rep(l, a.size())
    {
        result = min(result, dp[n][j][l]);
    }
    cout << result << endl;

    return 0;
}