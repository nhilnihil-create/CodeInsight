#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < n; i++)
class UnionFind
{
    vector<int> par;
    vector<int> siz;

public:
    UnionFind(int n) : par(n), siz(n, 1)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }
    int root(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        else
        {
            return par[x] = root(par[x]);
        }
    }
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
        {
            return 0;
        }
        if (siz[x] == siz[y])
        {
            swap(x, y);
        }
        siz[x] += siz[y];
        par[y] = x;
        return 1;
    }
    int size(int x)
    {
        return siz[root(x)];
    }
};
int main()
{
    int n, q, a, b;
    cin >> n >> q;
    int ans = n - 1;
    UnionFind uf(n);
    rep(i, q)
    {
        cin >> a >> b;
        a--;
        b--;
        if (uf.unite(a, b))
        {
            ans--;
        }
    }
    cout << ans << endl;
}
