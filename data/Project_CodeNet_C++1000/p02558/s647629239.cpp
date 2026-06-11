#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

class UnionFind {
public:
    vector<int> par;  // 各頂点の親
    vector<int> rank;  // 各頂点の深さ
    vector<int> sz;  // 各頂点の属する頂点の個数
    int sum_sz;  // 独立集合の個数

    // コンストラクタ
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            par.push_back(i);
            rank.push_back(0);
            sz.push_back(1);
        }
        sum_sz = n;
    }

    // 木の根を求める
    int find(int x) {
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    // x と y の属する集合を併合
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        // 深さが小さいものから大きい方の根へ辺を張る
        if (rank[x] < rank[y]) par[x] = y;
        else if (rank[x] > rank[y]) par[y] = x;
        else {
            par[y] = x;
            ++rank[x];
        }
        --sum_sz;
        sz[x] = sz[y] = sz[x] + sz[y];
    }

    // x と y が同じ木に属するかの判定
    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    // 頂点 x が属する集合の頂点数
    int size(int x) {
        return sz[find(x)];
    }

    // 独立した集合の個数(島の個数)
    int size() {
        return sum_sz;
    }
};

int main() {
    int N, Q;  cin >> N >> Q;
    UnionFind uf(N);
    for (int i = 0; i < Q; ++i) {
        int t, u, v;  cin >> t >> u >> v;
        if (t == 0) uf.unite(u, v);
        else cout << uf.is_same(u, v) << endl;
    }
}
