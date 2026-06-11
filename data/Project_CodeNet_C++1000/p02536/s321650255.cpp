#include <bits/stdc++.h>
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
struct UnionFind {
    vector<int> r;
    int ans;
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }
    UnionFind(int n) {
        r.assign(n + 1, -1);
        ans = n - 1;
    }
    void unite(int a, int b) {
        if (root(a) == root(b)) return;
        ans--;
        r[root(b)] = root(a);
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }
    cout << uf.ans << endl;
}