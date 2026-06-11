#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// union by size + path having
class UnionFind {
public:

    //素集合の要素の親（木構造の根）を配列*3で保持している．初期状態では頂点間の辺は存在せず，孤立した状態のため，自分自身を根として初期化している（par: parent の略）．
    vector <ll> par;

    // 各集合（木）の大きさ．根をたどるとその木の大きさが返されるように実装されている．この配列を用意しておくとある頂点の連結成分の大きさを簡単に求められる
    vector <ll> siz;

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

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

int main(){
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    rep(i, q) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) {
            uf.merge(u, v);
        }
        else {
            if(uf.issame(u, v)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}