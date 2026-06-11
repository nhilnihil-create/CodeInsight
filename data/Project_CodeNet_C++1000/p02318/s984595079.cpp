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

string s, t;
int ns, nt;
int dp[1001][1001];

int rec(int i, int j)
{
    int ret = 0;
    if (dp[i][j] > 0) return dp[i][j];
    if (i == ns) return nt - j;
    else if (j == nt) return ns - i;

    if (s[i] == t[j])
    {
        ret = rec(i + 1, j + 1); // match
    }
    else
    {
        int ret1, ret2, ret3;
        ret1 = rec(i + 1, j + 1) + 1; // replace
        ret2 = rec(i + 1, j) + 1; // delete s
        ret3 = rec(i, j + 1) + 1; // insert into s
        ret = MIN(ret1, MIN(ret2, ret3));
    }

    dp[i][j] = ret;
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> s >> t;

    ns = s.size();
    nt = t.size();
    rep (i, ns + 1) rep (j, nt + 1) dp[i][j] = 0;

    cout << rec(0, 0) << "\n";
    return 0;
}

