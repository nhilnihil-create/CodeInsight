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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    int dp[2];
    dp[0] = 0;
    dp[1] = 1;

    rep (i, n)
    {
        int now = s[i] - '0';
        int dp0 = MIN(dp[0] + now, dp[1] + 10 - now);
        int dp1 = MIN(dp[0] + now + 1, dp[1] + 10 - now - 1);
        dp[0] = dp0;
        dp[1] = dp1;
    }

    cout << MIN(dp[0], dp[1] + 1) << "\n";
    return 0;
}

