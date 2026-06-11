#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const int MOD = 1000000007;
const double pi = 3.141592653589;
/* class */
class DisjointSet {
public:
    // d[i] is root => d[i] < 0 & d[i] is the size of tree
    // d[i] is child => d[i] >= 0 & d[i] = i.parent
    vector<int> d;

    DisjointSet() {}
    DisjointSet(int size) : d(size, -1) {}

    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if ( d[x] > d[y] ) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }
};
/* global variables */
/* function */
/* main */
int main(){
    int n, m;
    cin >> n >> m;
    DisjointSet ds = DisjointSet(n);

    int ans = n - 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (!ds.same(a, b)) {
            ds.unite(a, b);
            ans--;
        }
    }
    cout << ans << '\n';

}
