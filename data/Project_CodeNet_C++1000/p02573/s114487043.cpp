#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union-Find木を利用
struct UnionFind {
    vector<int> par;

    UnionFind(int N) {
        par = vector<int>(N, -1);
    }

    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (par[rx] > par[ry]) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind tree(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        tree.unite(A, B);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, tree.size(i)); 
    }

    cout << ans << endl;
}