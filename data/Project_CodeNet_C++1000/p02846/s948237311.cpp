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

s64 T1, T2;
s64 A1, A2;
s64 B1, B2;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

    s64 diff = A1 * T1 + A2 * T2 - B1 * T1 - B2 * T2;
    if (diff == 0)
    {
        cout << "infinity\n";
        return 0;
    }

    u64 ans = 0;
    s64 diffAB1 = A1 * T1 - B1 * T1;
    s64 diffAB2 = A2 * T2 - B2 * T2;

    s64 temp1 = diffAB1 / diff;
    s64 temp2 = (diffAB2 - diffAB1) / diff;

    if ( temp1 < 0 || (temp1 == 0 && temp2 > 0) )
    {
        if (temp1 * diff == diffAB1) ans = 2 * (abs(temp1) - 1) + 2;
        else ans = 2 * abs(temp1) + 1;
    }
    cout << ans << "\n";
    return 0;
}

