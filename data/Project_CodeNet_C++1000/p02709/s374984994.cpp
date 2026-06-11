#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
ll N;
ll A[2020];
ll dp[2020][2020];
pair<ll, ll> AA[2020];

int main()
{
    cin >> N;
    rep(i, 0, N)
    {
        cin >> A[i];
        AA[i] = make_pair(A[i], i);
    }

    sort(AA, AA + N);
    reverse(AA, AA + N);

    ll ans = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N - i; j++)
        {
            auto next = AA[i + j - 1];
            if (i == 0 && j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + next.first * abs(next.second - (i - 1));
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] + next.first * abs((N - 1) - next.second - (j - 1));
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j] + next.first * abs(next.second - (i - 1)), dp[i][j - 1] + next.first * abs((N - 1) - next.second - (j - 1)));
            }
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}
