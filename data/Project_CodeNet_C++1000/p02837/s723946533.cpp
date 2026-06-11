#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> xy[n];
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            xy[i].push_back({x - 1, y});
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        bool h[n];
        rep(i, n) {
            if (bit & (1 << i))
                h[i] = 1;
            else
                h[i] = 0;
        }

        bool ok = true;
        rep(i, n) {
            if (h[i] == 0) continue;
            for (auto e : xy[i]) {
                if (h[e.first] != e.second) ok = false;
            }
        }

        if (ok) ans = max(ans, __builtin_popcount(bit));
    }

    cout << ans << endl;
    return 0;
}
