#include <bits/stdc++.h>
using namespace std;
int find(int x, auto &pa) { return pa[x] < 0 ? x : pa[x] = find(pa[x], pa); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> pa(n, -1);
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        int x = find(u, pa);
        int y = find(v, pa);
        if (t == 0) {
            if (x == y)
                continue;
            if (pa[x] > pa[y])
                swap(x, y);
            pa[x] += pa[y];
            pa[y] = x;
        } else {
            cout << (x == y) << '\n';
        }
    }
}