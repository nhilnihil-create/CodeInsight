#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n;
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}  //親は-1

    int root(int x) {
        if (par[x] < 0)
            return x;  //自身が親
        else
            return par[x] = root(par[x]);  //再帰
    }

    bool same(int x, int y) { return root(x) == root(y); }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;  //既に同じ根
        // xとyのサイズの大きいほうにまとめたい
        if (size(x) < size(y)) swap(x, y);
        par[x] += par[y];  //根のparは-(要素数)になる
        par[y] = x;        //親を更新
        return;
    }

    int size(int x) { return -par[root(x)]; }
};

signed main() {
    int m;
    cin >> n >> m;
    int a, b;
    UnionFind tree(n);
    rep(i, 0, m) {
        cin >> a >> b;
        tree.merge(--a, --b);
    }
    int cnt = 0;
    rep(i, 0, n) if (tree.root(i) == i) cnt++;
    cout << cnt - 1 << "\n";
}