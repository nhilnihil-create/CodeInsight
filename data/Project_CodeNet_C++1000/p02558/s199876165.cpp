#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> sz;

    UnionFind(int n=0){ if(n>0) initialize(n); }
    void initialize(int n){
        par.resize(n);
        sz.assign(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }

    bool unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        if(sz[x] > sz[y]) swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        return true;
    }

    bool same(int x, int y){ return find(x) == find(y); }
    int size(int x){ return sz[find(x)]; }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    while(Q--){
        int t, a, b;
        cin >> t >> a >> b;
        if(t){
            cout << uf.same(a, b) << endl;
        }else{
            uf.unite(a, b);
        }
    }
    return 0;
}
