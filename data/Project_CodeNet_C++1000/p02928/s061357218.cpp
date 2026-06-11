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

    s64 n, k;
    cin >> n >> k;

    vs32 a(n);
    rep (i, n) cin >> a[i];

    s64 tento = 0;
    rep (i, n)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] > a[j]) ++tento;
        }
    }

    vs64 c(n);
    rep (i, n)
    {
        rep (j, n)
        {
            if (a[i] < a[j]) ++c[i];
        }
    }

    s64 ans = tento * k % MOD;
    rep (i, n)
    {
        ans = (ans + (c[i] * (k * (k - 1) / 2 % MOD)) % MOD) % MOD;
    }

    cout << ans << "\n";
    return 0;
}

