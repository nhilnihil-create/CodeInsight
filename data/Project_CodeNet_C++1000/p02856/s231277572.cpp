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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m;
    cin >> m;
    s64 d, c;
    s64 ans = 0;
    s64 num = 0;
    rep (i, m)
    {
        cin >> d >> c;
        num += d * c;
        ans += c;
    }
    --ans;
    s64 u = num / 10;
    d = num % 10;

    while (u >= 10)
    {
        ans += u / 10 * 10;
        u = u % 10 + u / 10;
    }

    while (u > 0)
    {
        ans += u;
        s64 temp = u + d;
        u = temp / 10;
        d = temp % 10;
    }

    cout << ans << "\n";
    return 0;
}

