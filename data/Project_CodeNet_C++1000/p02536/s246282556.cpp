#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct UnionFind {
    vector<ll> par;
    ll count = 0;
    UnionFind(ll n) : par(n) {
        for (ll i = 0; i < n; i++) {
            par[i] = i;
            if (i == 0) count = n;
        }
    }
  
    ll root(ll x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
  
    void unite(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
        count --;
    }
  
    bool same(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll ans() {
        return count-1;
    }
};

int main () {
    ll n, m;
    cin >> n >> m;

    UnionFind tree(n);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        tree.unite(a,b);
    }

    cout << tree.ans() << endl;
}