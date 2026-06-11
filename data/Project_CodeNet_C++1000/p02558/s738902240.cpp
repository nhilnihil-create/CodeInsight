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
    bool same(long long x, long long y) { return root(x) == root(y); }
    int root(long long x) { return par[x] < 0 ? x : par[x] = root(par[x]); }
    int size(long long x) { return -par[root(x)]; }
};

int main()
{
    int n, q;
    cin >> n >> q;
    UnionFind tree(n);
    for(int i = 0; i < q; i++) {
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        if(t == 0) tree.unite(u, v);
        else cout << (tree.same(u, v) ? 1 : 0) << endl;
    }
    return 0;
}
