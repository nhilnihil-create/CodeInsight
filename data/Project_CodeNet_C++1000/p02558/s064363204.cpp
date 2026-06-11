#include<bits/stdc++.h>
using namespace std;
struct UnionFind{

    vector<int> par;
    vector<int> sizes;

    UnionFind(int n) : par(n), sizes(n, 1) {
        for(int i=0;i<n;i++) par[i] = i;
    }

    // データxが属する木の根を得る
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
    }

    // 2つのデータx, yが属する木をマージする
    void unite(int x, int y) {
        // データの根ノードを得る
        x = find(x);
        y = find(y);
        // 既に同じ木に属しているならマージしない
        if (x == y) return;
        // xの木がyの木より大きくなるようにする
        if (sizes[x] < sizes[y]) swap(x, y);
        // xがyの親になるように連結する
        par[y] = x;
        sizes[x] += sizes[y];
    }

    // 2つのデータx, yが属する木が同じならtrueを返す
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // データxが含まれる木の大きさを返す
    int size(int x) {
        return sizes[find(x)];
    }
};
int main(){
    int n, q;
    cin >> n >> q;
    UnionFind UF(n);
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t==0) UF.unite(u, v);
        else cout << UF.same(u, v) << endl;
    }
}