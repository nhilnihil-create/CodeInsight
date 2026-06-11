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
    map<int, int> m;
    int a;
    rep (i, n)
    {
        cin >> a;
        ++m[a];
    }

    bool ans;
    if (m.size() == 1)
    {
        ans = m[0] > 0;
    }
    else if (m.size() == 2)
    {
        if (n % 3 != 0)
        {
            ans = false;
        }
        else
        {
            vs32 b(2), c(2);
            int cnt = 0;
            for (auto& x : m)
            {
                b[cnt] = x.first;
                c[cnt] = x.second;
                ++cnt;
            }
            if (c[0] * 2 == c[1])
            {
                ans = b[0] == 0;
            }
            else if (c[1] * 2 == c[0])
            {
                ans = b[1] == 0;
            }
            else
            {
                ans = false;
            }
        }
    }
    else if (m.size() == 3)
    {
        if (n % 3 != 0)
        {
            ans = false;
        }
        else
        {
            vs32 b(3), c(3);
            int cnt = 0;
            for (auto& x : m)
            {
                b[cnt] = x.first;
                c[cnt] = x.second;
                ++cnt;
            }
            if (c[0] == c[1] && c[1] == c[2] && c[2] == c[0])
            {
                ans = (b[0] ^ b[1]) == b[2];
            }
            else
            {
                ans = false;
            }
        }
    }
    else
    {
        ans = false;
    }

    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}

