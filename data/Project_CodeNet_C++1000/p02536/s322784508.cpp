/**
*    author:  boutarou
*    created: 28.09.2020 18:15:31
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); i++)
using ll = long long;
using P = pair<int, int>;

class UnionFind {
    private:
        vector<int>par;
    public:
        UnionFind(int n) {
            for (int i = 0; i < n; i++) par.push_back(-1);
        }
        int root(int x) {
            if (par[x] < 0) return x;
            else return par[x] = root(par[x]);
        }
        bool same(int x, int y) { return root(x) == root(y);}
        void unite(int x, int y) {
            x = root(x), y = root(y);
            if (x == y) return;
            if (par[x] > par[y]) swap(x, y);
            par[x] += par[y];
            par[y] = x;
            return;
        }
        int size(int x) { return -par[root(x)];}
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int ans = n - 1;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (!uf.same(a, b)) {
            uf.unite(a, b);
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}