#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    vector<vector<vector<ll>>> dp((n + (k - 1)) / k + 1, vector<vector<ll>>(k, vector<ll>(3, 0)));
    rep(i, n)
    {
        char hand = t[i];
        int idx_offset = i % k;
        int idx_num = i / k + 1;
        if (hand == 'r')
        {
            dp[idx_num][idx_offset][0] += max(dp[idx_num - 1][idx_offset][1], dp[idx_num - 1][idx_offset][2]);
            dp[idx_num][idx_offset][1] += max(dp[idx_num - 1][idx_offset][0], dp[idx_num - 1][idx_offset][2]);
            dp[idx_num][idx_offset][2] += max(dp[idx_num - 1][idx_offset][0], dp[idx_num - 1][idx_offset][1]) + p;
        }
        else if (hand == 's')
        {
            dp[idx_num][idx_offset][0] += max(dp[idx_num - 1][idx_offset][1], dp[idx_num - 1][idx_offset][2]) + r;
            dp[idx_num][idx_offset][1] += max(dp[idx_num - 1][idx_offset][0], dp[idx_num - 1][idx_offset][2]);
            dp[idx_num][idx_offset][2] += max(dp[idx_num - 1][idx_offset][0], dp[idx_num - 1][idx_offset][1]);
        }
        else
        {
            dp[idx_num][idx_offset][0] += max(dp[idx_num - 1][idx_offset][1], dp[idx_num - 1][idx_offset][2]);
            dp[idx_num][idx_offset][1] += max(dp[idx_num - 1][idx_offset][0], dp[idx_num - 1][idx_offset][2]) + s;
            dp[idx_num][idx_offset][2] += max(dp[idx_num - 1][idx_offset][0], dp[idx_num - 1][idx_offset][1]);
        }
    }
    ll r_max, s_max, p_max;

    ll res = 0;
    for (int j = 0; j < k; j++)
    {
        r_max = 0;
        s_max = 0;
        p_max = 0;
        for (int i = (n + (k - 1)) / k; i >= 0; i--)
        {
            r_max = MAX(r_max, dp[i][j][0]);
            s_max = MAX(s_max, dp[i][j][1]);
            p_max = MAX(p_max, dp[i][j][2]);
            if (min({r_max, s_max, p_max}) > 0)
                break;
        }
        res += max({r_max, s_max, p_max});
    }
    cout << res << endl;
    return 0;
}