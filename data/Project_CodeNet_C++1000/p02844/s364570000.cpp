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
    vector< vs32 > pos(10);
    rep (i, n)
    {
        char c;
        cin >> c;
        pos[c - '0'].push_back(i);
    }

    int ans = 0;
    rep (i, 10) rep (j, 10) rep (k, 10)
    {
        auto l = lower_bound(pos[i].begin(), pos[i].end(), 0);
        if (l == pos[i].end()) continue;
        auto m = upper_bound(pos[j].begin(), pos[j].end(), *l);
        if (m == pos[j].end()) continue;
        auto r = upper_bound(pos[k].begin(), pos[k].end(), *m);
        if (r == pos[k].end()) continue;
        ++ans;
    }

    cout << ans << "\n";
    return 0;
}

