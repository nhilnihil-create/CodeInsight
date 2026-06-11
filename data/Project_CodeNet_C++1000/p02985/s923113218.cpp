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

int n, k;
vector< vs32 > g;
vs64 d;
vector< bool > reached;

void dfs(int u, int p)
{
    if (reached[u]) return;
    reached[u] = true;

    int sub = (p == -1 ? 1 : 2);
    for (auto& v : g[u])
    {
        if (!reached[v]) { d[v] -= sub; ++sub; }
        dfs(v, u);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    g.resize(n);
    int u, v;
    rep (i, n - 1)
    {
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    d.resize(n, k);
    reached.resize(n, false);
    dfs(0, -1);

    s64 ans = 1;
    rep (i, n)
    {
        ans = (ans * d[i]) % MOD;
    }

    cout << ans << "\n";
    return 0;
}

