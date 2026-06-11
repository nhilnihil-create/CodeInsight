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

    int n;
    cin >> n;

    s64 dp[n];
    rep (i, n) dp[i] = 0;
    dp[0] = 1;
    rep (i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        dp[b] -= a + 1;
    }

    s64 ans = dp[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i] += dp[i - 1] + i + 1;
        ans += dp[i];
    }

    cout << ans << "\n";
    return 0;
}

