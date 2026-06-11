#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;
using namespace std;
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
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

int n, m, q;
vector<int> a, b, c, d;
int ans = 0;
void dfs(vector<int> v) {
    int length = v.size();

    if (length == n) {
        
        int t = 0;
        for (int i = 0; i < q; i++) {

            if (v[b[i] - 1] - v[a[i] - 1] == c[i]) t += d[i];

        }

        ans = max(ans, t);
        return;
    }

    int now = v[length - 1];
    for (int i = now; i <= m; i++) {
        vector<int> v2 = v;
        v2.push_back(i);
        dfs(v2);
    }
    return;
}

int main() {

    int ai, bi, ci, di;

    cin >> n >> m >> q;


    for (int i = 0; i < q; i++) {
        cin >> ai >> bi >> ci >> di;
        a.push_back(ai);
        b.push_back(bi);
        c.push_back(ci);
        d.push_back(di);
    }

    for (int i = 1; i <= m; i++) {

        vector<int> g;
        g.push_back(i);

        dfs(g);

    }

    cout << ans << endl;

}