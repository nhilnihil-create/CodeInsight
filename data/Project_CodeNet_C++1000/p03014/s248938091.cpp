// 7/1 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

P dp[2000][2000];

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    rep(i, H) cin >> field[i];

    rep(h, H) rep(w, W) dp[h][w] = P(-1, -1);

    // cout << "here?" << endl;

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (field[h][w] == '#') continue;

            if (h > 0) dp[h][w].first = dp[h-1][w].first;
            if (w > 0) dp[h][w].second = dp[h][w-1].second;

            // 上端または１つ上が障害物の時は、新しく縦向きに走査する。
            if (h == 0 || dp[h][w].first == -1) {
                int nh = h;
                while (nh < H && field[nh][w] != '#') nh++;
                dp[h][w].first = nh - h;  // 自分を含む。[h, nh)
            }

            // 左端または左側が障害物の時は、新しく横向きに走査する。
            if (w == 0 || dp[h][w].second == -1) {
                int nw = w;
                while (nw < W && field[h][nw] != '#') nw++;
                dp[h][w].second = nw - w;
            }
        }
    }

    // cout << "here?2" << endl;

    int res = 0;
    rep(h, H) {
        rep(w, W) {
            if (field[h][w] == '#') continue;
            int now = dp[h][w].first + dp[h][w].second - 1;
            res = max(res, now);
        }
    }
    cout << res << endl;
}