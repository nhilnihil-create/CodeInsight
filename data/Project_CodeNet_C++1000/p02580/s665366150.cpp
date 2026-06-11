#include <bits/stdc++.h>
using namespace std;
// #define int long long
// typedef long long ll;


int32_t main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n, m; cin >> n >> m;
    int q; cin >> q;
    vector<vector<int>> l(n), r(m);
    for (; q; q--) {
        int x, y; cin >> x >> y; x--; y--;
        l[x].push_back(y); r[y].push_back(x);
    }
    int mxl = l[0].size();
    for (int i = 1; i < n; i++) mxl = max(mxl, (int)l[i].size());
    int mxr = r[0].size();
    for (int i = 0; i < m; i++) mxr = max(mxr, (int)r[i].size());
    vector<int> lft, rght;
    for (int i = 0; i < n; i++) {
        sort(l[i].begin(), l[i].end());
        if (l[i].size() == mxl) lft.push_back(i);
    }
    for (int i = 0; i < m; i++) {
        sort(r[i].begin(), r[i].end());
        if (r[i].size() == mxr) rght.push_back(i);
    }
    bool fl = false;
    for (auto i : lft) {
        int x = 0, y = 0;
        while (x < l[i].size() && y < rght.size()) {
            if (l[i][x] < rght[y]) x++;
            else {
                if (l[i][x] != rght[y]) {
                    fl = true; break;
                }
                y++;
            }
        }
        if (y != rght.size()) fl = true;
        if (fl) break;
    }
    if (fl) cout << mxl + mxr << endl;
    else cout << mxl + mxr - 1 << endl;

    return 0;
}
