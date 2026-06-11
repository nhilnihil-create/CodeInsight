#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second

using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;

template <typename A, typename B>
inline void chmin(A& a, B b) {
    if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A& a, B b) {
    if (a < b) a = b;
}

template <class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>& p) {
    ost << "{" << p.first << "," << p.second << "}";
    return ost;
}

template <class T>
ostream& operator<<(ostream& ost, const vector<T>& v) {
    ost << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) ost << ",";
        ost << v[i];
    }
    ost << "}";
    return ost;
}

inline int topbit(unsigned long long x) {
    return x ? 63 - __builtin_clzll(x) : -1;
}

inline int popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x) {
    return __builtin_parity(x);
}

struct UnionFindTree {
    vector<int32_t> par, sz;
    UnionFindTree(int32_t n = 0) : par(n), sz(n) {
        for (int32_t i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int32_t find(int32_t x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    void unite(int32_t x, int32_t y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    bool same(int32_t x, int32_t y) {
        return find(x) == find(y);
    }
    int32_t size(int32_t x) {
        return sz[find(x)];
    }
};

signed main() {
    int N, M;
    cin >> N >> M;
    UnionFindTree uf(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
    }

    int ans = 0;
    rep(i, N) chmax(ans, uf.size(i));
    cout << ans << endl;
    return 0;
}