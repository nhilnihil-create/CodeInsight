#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

using P = pair<ll, ll>;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}

    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    int N;
    cin >> N;
    vector<Point> p(N);
    rep(i, N) cin >> p[i].x >> p[i].y;

    set<P> dist;
    rep(i, N) {
        for (int j = i + 1; j < N; j++) {
            int dx = p[i].x - p[j].x;
            int dy = p[i].y - p[j].y;
            if (dx != 0 || dy != 0) dist.insert(P{dx, dy});
        }
    }

    int ans = N;
    for (auto d: dist) {
        UnionFind uf(N);
        rep(i, N) rep(j, N) if (p[j].x + d.first == p[i].x && p[j].y + d.second == p[i].y) uf.merge(i, j);
        int now = 0;
        rep(i, N) if (uf.root(i) == i) now++;
        chmin(ans, now);
    }
    cout << ans << endl;
}