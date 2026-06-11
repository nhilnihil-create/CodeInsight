#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int,int>;

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0): d(n,-1) {}
    int findRoot(int x) {
        if (d[x] < 0) return x;
        return d[x] = findRoot(d[x]);
    }
    bool unite(int x, int y) {
        x = findRoot(x); y = findRoot(y);
        if(x == y) return false;
        if(d[x] > d[y]) swap(x,y); //-d[x] < -d[y]
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return findRoot(x) == findRoot(y);}
    int size(int x) { return -d[findRoot(x)];}
};

int deg[100005];
vector<int> to[100005];

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a,b);
    }
    int ans = 0;
    for(int i = 0;i < n;i++) {
        ans = max(ans, uf.size(i));
    }
    cout << ans << endl;
    return 0;
}