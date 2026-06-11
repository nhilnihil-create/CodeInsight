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

class Graph
{
public:
    enum
    {
        WHITE = 0,
        GRAY = 1,
        BLACK = 2,
    };

    Graph() {}
    Graph(int n)
    : color(n, WHITE), M(n, vs32(n, INFTY)), d(n, INFTY), p(n, -1)
    {}
    ~Graph() {}

    void prim(int s)
    {
        d[s] = 0;
        
        while (true)
        {
            int minv = INFTY;
            int u = -1;
            rep (i, color.size())
            {
                if (color[i] != BLACK && minv > d[i])
                {
                    minv = d[i];
                    u = i;
                }
            }

            if (u < 0) break;
            d[u] = minv;
            color[u] = BLACK;

            rep (v, color.size())
            {
                if (color[v] != BLACK && d[v] > d[u] + M[u][v])
                {
                    d[v] = d[u] + M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    static const int INFTY = 1e9;
    vs32 color;
    vector< vs32 > M;
    vs32 d;
    vs32 p;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    Graph g(n);

    int u, v;
    int w;
    int c;
    rep (i, n)
    {
        cin >> u >> c;
        rep (j, c)
        {
            cin >> v >> w;
            g.M[u][v] = w;
        }
    }

    g.prim(0);
    rep (i, n)
    {
        cout << i << " " << g.d[i] << "\n";
    }
    return 0;
}

