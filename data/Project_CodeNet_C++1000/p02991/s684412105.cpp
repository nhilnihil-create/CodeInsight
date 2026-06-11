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

    int n, m;
    cin >> n >> m;
    vector<vs32> g(3 * n);
    int s, t;
    rep (i, m)
    {
        cin >> s >> t;
        --s; --t;
        g[s].push_back(t + n);
        g[s + n].push_back(t + 2 * n);
        g[s + 2 * n].push_back(t);
    }

    cin >> s >> t;
    --s; --t;
    vs32 d(3 * n, 1e9);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto v : g[u])
        {
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }


    int ans = (d[t] == 1e9 ? -1 : d[t] / 3);

    cout << ans << "\n";
    return 0;
}

