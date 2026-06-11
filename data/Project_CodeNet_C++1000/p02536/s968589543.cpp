#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

int N, M;

struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int N) : par(N), rank(N) {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        if (rank[rx] == rank[ry]) rank[rx]++;
        par[ry] = rx;
    }

    bool is_same(int x, int y) {
        return root(x) == root(y);
    }
};


int main() {
    cin >> N >> M;
    UnionFind tree(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        tree.merge(A-1, B-1);
    }

    set<int> roots;
    for (int i = 0; i < N; i++) {
        roots.insert(tree.root(i));
    }

    cout << roots.size() - 1 << endl;

    return 0; 
}
