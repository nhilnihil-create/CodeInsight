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

using P = pair<int, int>;

class graph
{
public:
    vector< vs32 > g;
    vs32 d;
    int num;

    graph() {}
    ~graph() {}
    graph(int size)
    : g(vector< vs32 >(size)), d(vs32(size, 1e9)), num(size)
    {}

    void dijkstra(int s)
    {
        vector< bool > reached(num, false);

        priority_queue< P > pq;
        pq.push(P{0, s});
        while (!pq.empty())
        {
            P du = pq.top(); pq.pop();
            int dist = -du.first;
            int u = du.second;

            if (reached[u]) continue;
            reached[u] = true;
            d[u] = dist;

            for (auto v : g[u])
            {
                if (!reached[v] && d[v] > dist + 1)
                {
                    pq.push(P{-(dist + 1), v});
                }
            }
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    graph g(3 * n);
    int s, t;
    rep (i, m)
    {
        cin >> s >> t;
        --s; --t;
        g.g[s].push_back(t + n);
        g.g[s + n].push_back(t + 2 * n);
        g.g[s + 2 * n].push_back(t);
    }

    cin >> s >> t;
    --s; --t;
    g.dijkstra(s);

    int ans = (g.d[t] == 1e9 ? -1 : g.d[t] / 3);

    cout << ans << "\n";
    return 0;
}

