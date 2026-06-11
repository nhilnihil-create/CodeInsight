#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (ll i = 0; i < (o);i++)
#define rep_s(i, o) for (int i = 1; i <= (o);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


template<class T>
bool chmax(T &a, const T &b) { if (a < b) { return b; } return a; }

template<class T>
bool chmin(T &a, const T &b) { if (a > b) { a = b; return a; } return a; }

struct UnionFind {
    // 自身が根(=親)なら、その集合に属する頂点の数に -1 をかけたもの
    vector<int> d;
    UnionFind(int n=0): d(n,-1) {}
    int find(int x) {   // root 
        // cout << d[x] << endl;
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        // printf("bef : d[%d] = %d, d[%d] = %d\n", x, d[x], y, d[y]);
        if (x == y) return false; // くっつけられたかの情報が必要な時に(ex. MST)で便利
        if (d[x] > d[y]) swap(x,y); // -d[x] < -d[y] 
        d[x] += d[y];
        d[y] = x;
        // printf("aft : d[%d] = %d, d[%d] = %d\n", x, d[x], y, d[y]);
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -d[find(x)];}
};

const int MOD = 1000000007;
int main() {
    ll n, m; cin >> n >> m;
    UnionFind uf(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        uf.unite(a, b);
    }
    int ans = 0;
    rep(i, n) ans = max(ans, uf.size(i));
    cout << ans << endl;
    return 0;
}