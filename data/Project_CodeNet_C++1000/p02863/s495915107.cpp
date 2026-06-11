#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

// vector<int> A(3010), B(3010);
// vector<P> C(3010);
// int dp[3010][3010];

#define chmax(x, y) x = max(x, y)

int dp[3005][3005];

int main()
{
    int n, t;
    cin >> n >> t;
    vector<P> p(n);
    rep(i, n)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());

    int ans = 0;

    rep(i, n)
    {
        rep(j, t)
        {
            chmax(dp[i + 1][j], dp[i][j]);
            if (j - p[i].first >= 0) {
                chmax(dp[i + 1][j], dp[i][j - p[i].first] + p[i].second);
            }
        }
        int now = dp[i][t - 1] + p[i].second;
        chmax(ans, now);
    }

    cout << ans << endl;

    return 0;
}