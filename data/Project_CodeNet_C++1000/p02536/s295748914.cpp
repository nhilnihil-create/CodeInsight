#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

struct UnionFind {
    UnionFind() {}
    UnionFind(int n) {
        par.resize(n, -1);
    }
    
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    
    bool merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return false;
        if (par[rx] > par[ry]) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return true;
    }
    
    bool is_same(int x, int y) {
        return (root(x) == root(y));
    }
    
    int size(int x) {
        return -par[root(x)];
    }
    
private:
    vector<int> par;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        uf.merge(a, b);
    }
    set<ll> s;
    rep(i, n) s.insert(uf.root(i));
    cout << (sz(s) - 1) << endl;
    return 0;
}
