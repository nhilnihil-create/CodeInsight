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

    multiset<int> s;
    rep (i, 1 << n)
    {
        int temp;
        cin >> temp;
        s.insert(-temp);
    }

    // for (auto& x : s)
    // {
    //     cout << -x << " ";
    // }
    // cout << "\n";

    bool ans = true;
    vs32 t(1 << n);
    t[0] = -*s.begin();
    rep (i, n)
    {
        for (int j = 0; j < (1 << i); ++j)
        {
            auto it = s.upper_bound(-t[j]);
            if (it == s.end())
            {
                ans = false;
                break;
            }
            int temp = *it;
            t[(1 << i) + j] = -temp;
            s.erase(it);
        }
        if (!ans) break;
    }

    // sort(t.begin(), t.end());

    // rep (i, 1 << n) cout << t[i] << " ";
    // cout << "\n";

    cout << (ans ? "Yes\n" : "No\n");

    return 0;
}

