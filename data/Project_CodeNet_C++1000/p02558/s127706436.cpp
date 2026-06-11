#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

class DisjointSet {
   private:
    vector<int> rank, parent;

   public:
    DisjointSet() {}
    DisjointSet(int size) {
        rank.resize(size, 0);
        parent.resize(size, 0);
        rep(i, size) { makeSet(i); }
    }

    void makeSet(int x) {
        parent[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y) { return findSet(x) == findSet(y); }

    void unite(int x, int y) { link(findSet(x), findSet(y)); }

    void link(int x, int y) {
        if (x == y) {
            return;
        }
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    int findSet(int x) {
        if (x != parent[x]) {
            parent[x] = findSet(parent[x]);
        }
        return parent[x];
    }
};
int n, q;

int main() {
    scanf("%d%d", &n, &q);
    DisjointSet ds(n);
    rep(i, q) {
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 0) {
            ds.unite(u, v);
        } else {
            printf("%d\n", ds.same(u, v));
        }
    }
    return 0;
}