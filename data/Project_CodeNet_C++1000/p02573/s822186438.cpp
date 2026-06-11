#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
const ll mod = 1000000000 + 7; //10^9


struct unionfind
{
    vector<long long> d;

    unionfind(long long n) : d(n, -1) {}

    long long root(long long x)
    {
        if (d[x] < 0)
        {
            return x;
        }
        else
        {
            return d[x] = root(d[x]);
        }
    }

    bool unite(long long x, long long y)
    {
        x = root(x);
        y = root(y);

        if (x == y)
        {
            return false;
        }

        if (d[x] > d[y])
        {
            swap(x, y);
        }

        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(long long x, long long y)
    {
        return root(x) == root(y);
    }

    long long size(long long x)
    {
        return -d[root(x)];
    }
};
int main() {
    int N, M;
    cin >> N >> M;
    unionfind L(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        L.unite(a, b);
        
    }
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, L.size(i));
    }
    
    cout << ans << endl;
    
}