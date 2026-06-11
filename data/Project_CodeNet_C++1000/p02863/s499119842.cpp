#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <numeric>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))

using P = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    vector< P > ab(n);
    rep (i, n)
    {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(), ab.end());

    int dp[n + 1][t + 1];
    rep (i, n + 1) rep (j, t + 1) dp[i][j] = 0;

    rep (i, n)
    {
        rep (j, t)
        {
            if (j < ab[i].first)
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = MAX(dp[i][j], dp[i][j - ab[i].first] + ab[i].second);
            }
        }
        dp[i + 1][t] = MAX(dp[i][t], dp[i][t - 1] + ab[i].second);
    }

    cout << dp[n][t] << "\n";
    return 0;
}

