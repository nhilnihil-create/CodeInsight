#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
template <class T> vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
template <typename T> struct edge {
    int to;
    T cost;
    edge(int t, T c) : to(t), cost(c) {}
};
template <typename T> using WGraph = vector<vector<edge<T>>>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

// UnionFind
struct UnionFind {
    vector<int> par;
    vector<int> siz;

    UnionFind(int N) : par(N), siz(N, 1LL) {
        for(int i = 0; i < N; i++)
            par[i] = i;
    }
    int root(int x) {
        if(par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry)
            return;
        if(siz[rx] < siz[ry])
            swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x) { return siz[root(x)]; }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    rep(i, Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) {
            uf.unite(u, v);
        } else {
            cout << (uf.same(u, v) ? 1 : 0) << endl;
        }
    }
}