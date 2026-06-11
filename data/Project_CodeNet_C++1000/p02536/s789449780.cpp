#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
// const ll MOD = 998244353;
const double PI=3.14159265358979323846;

// 出典:https://pyteyon.hatenablog.com/entry/2019/03/11/200000
// union by size + path having
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    // void init(ll sz_) {
    //     par.resize(sz_);
    //     siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
    //     for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    // }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};



int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int ans = n-1;
    rp(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(!uf.issame(a, b)) {
            uf.merge(a, b);
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
    
}
