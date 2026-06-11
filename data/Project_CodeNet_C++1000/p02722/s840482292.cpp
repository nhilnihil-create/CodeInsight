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


// ABC161 F

void common_multiple(s64 x, vs64& ret)
{
    for (s64 i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            if (x / i != i) ret.push_back(x / i);
            ret.push_back(i);
        }
    }
    if (x != 1) ret.push_back(x);
}

s64 solve1(s64 x)
{
    s64 ret = 0;
    vs64 cand;
    common_multiple(x, cand);
    rep (i, cand.size())
    {
        s64 div = cand[i];
        s64 temp = x;
        while (temp % div == 0) temp /= div;
        if (temp % div == 1) ++ret;
    }
    return ret;
}

s64 solve2(s64 x)
{
    vs64 ret;
    common_multiple(x, ret);
    return ret.size();
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    s64 n;
    cin >> n;

    cout << solve1(n) + solve2(n - 1) << "\n";
    return 0;
}

