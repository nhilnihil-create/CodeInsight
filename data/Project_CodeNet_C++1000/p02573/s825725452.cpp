#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

struct UnionFind {
    vector<int> parent;

    UnionFind(int N) {
        parent = vector<int>(N, -1);
    }

    int root(int x) {
        if (parent[x] < 0) return x;
        return root(parent[x]);
    }

    int size(int x) {
        return -parent[root(x)];
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);

    UnionFind tree(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree.unite(a, b);
    }    

    int ans = 1;

    rep(i, n) {
        ans = max(ans, tree.size(i));
    }
    
    cout << ans << endl;
    return 0;
}