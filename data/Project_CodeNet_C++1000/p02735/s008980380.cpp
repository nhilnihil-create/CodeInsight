#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// https://atcoder.jp/contests/agc043/tasks/agc043_a
P mv[2] = { P(1, 0), P(0, 1) };
vector<string> s;
int h, w;
int dp[110][110];

void solve()
{
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                int ni = i + mv[k].first;
                int nj = j + mv[k].second;
                if (ni >= h || nj >= w)
                    continue;

                if (s[i][j] == '.' && s[ni][nj] == '#')
                {
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1);
                }
                else
                {
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j]);
                }
            }
        }
    }
}

int main()
{
    cin >> h >> w;
    s.resize(h);
    for (int i = 0; i < h; ++i) cin >> s[i];
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            dp[i][j] = numeric_limits<int>::max();
        }
    }

    if (s[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;
    solve();
    cout << dp[h-1][w-1] << endl;
    return 0;
}
