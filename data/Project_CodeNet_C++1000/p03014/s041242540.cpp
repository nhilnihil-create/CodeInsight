#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> c(H);
    rep(i, H) cin >> c[i];

    int ans = 0;
    vector<vector<int>> cnt(H, vector<int>(W, 0));
    rep(i, H) {
        int l = 0, r = 0;
        while (l < W) {
            if (r >= W || c[i][r] == '#') {
                if (r != l)
                    for (int j = l; j < r; ++j) {
                        cnt[i][j] = r - l;
                    }
                ++r, l = r;
            } else
                ++r;
        }
    }
    rep(i, W) {
        int l = 0, r = 0;
        while (l < H) {
            if (r >= H || c[r][i] == '#') {
                if (r != l)
                    for (int j = l; j < r; ++j) {
                        ans = max(ans, cnt[j][i] + r - l - 1);
                    }
                ++r, l = r;
            } else
                ++r;
        }
    }

    cout << ans << endl;
}
