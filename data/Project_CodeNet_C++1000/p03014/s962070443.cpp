#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    rep(i, H) cin >> s[i];

    vector<vector<int>>
        r(H, vector<int>(W)),
        l(H, vector<int>(W)),
        u(H, vector<int>(W)),
        d(H, vector<int>(W));

    rep(i, H) {
        int now = 0;
        rep(j, W) {
            if (s[i][j] == '#')
                now = 0;
            else
                ++now;
            l[i][j] = now;
        }
    }

    rep(i, H) {
        int now = 0;
        for (int j = W - 1; j >= 0; --j) {
            if (s[i][j] == '#')
                now = 0;
            else
                ++now;
            r[i][j] = now;
        }
    }

    rep(i, W) {
        int now = 0;
        rep(j, H) {
            if (s[j][i] == '#')
                now = 0;
            else
                ++now;
            u[j][i] = now;
        }
    }

    rep(i, W) {
        int now = 0;
        for (int j = H - 1; j >= 0; --j) {
            if (s[j][i] == '#')
                now = 0;
            else
                ++now;
            d[j][i] = now;
        }
    }

    int ans = 0;
    rep(i, H) rep(j, W)
        ans = max(ans, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);

    cout << ans << endl;

    return 0;
}