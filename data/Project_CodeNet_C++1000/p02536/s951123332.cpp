#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<long long> par;
    UnionFind(long long size) : par(size + 1, -1) {}
    bool unite(long long x, long long y){
        x = root(x);
        y = root(y);
        if(x != y) {
            if(par[y] < par[x]) swap(x, y);
            par[x] += par[y];
            par[y] = x;
        }
        return x != y;
    }
    bool same(long long x, long long y){ return root(x) == root(y); }
    int root(long long x){ return par[x] < 0 ? x : par[x] = root(par[x]); }
    int size(long long x){ return -par[root(x)]; }
};

int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind tree(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.unite(a, b);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(tree.root(i) == i) ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}
