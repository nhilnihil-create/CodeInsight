#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

namespace asl
{
    class DisjointSet
    {
    public:
        std::vector<int> ds;

        DisjointSet(int n)
        {
            ds = std::vector<int>(n, -1);
        }

        int root(int a)
        {
            return ds[a] < 0 ? a : ds[a] = root(ds[a]);
        }

        bool join(int u, int v)
        {
            u = root(u), v = root(v);

            if (u == v)
                return false;

            if (ds[u] < ds[v])
                std::swap(u, v);

            ds[v] += ds[u];
            ds[u] = v;

            return true;
        }

        bool same(int u, int v)
        {
            return root(u) == root(v);
        }

    };
} 

#include <experimental/optional>

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, q;
    cin >> n >> q;

    DisjointSet ds(n);

    while (q--)
    {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0)
        {
            ds.join(u, v);
        }
        else
        {
            cout << ds.same(u, v) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}


