#include <bits/stdc++.h>

#include <utility>
#include <vector>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

int main() {
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> hs(H), ws(W);
    set<P> s;  // 爆破対象がある座標
    rep(i, M) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        hs[r]++;
        ws[c]++;
        s.emplace(r, c);
    }
    int mh = 0, mw = 0;
    rep(i, H) mh = max(mh, hs[i]);  // 縦向きに爆破対象が置かれている数の最大値
    rep(i, W) mw = max(mw, ws[i]);  // 横向きに爆破対象が置かれている数の最大値
    vector<int> is, js;
    rep(i, H) if (mh == hs[i]) is.push_back(i);  // 最大値の場所
    rep(i, W) if (mw == ws[i]) js.push_back(i);  // 最大値の場所
    int ans = mh + mw;                           // ありえる最大値
    for (int i : is) {
        for (int j : js) {
            if (s.count(P(i, j)))  // 2回数えてしまっているので、ありえる最大値が出せない
                continue;
            cout << ans << endl;  // 最大値が出せる
            return 0;
        }
    }
    // 最大値が出せない
    ans--;
    cout << ans << endl;
    return 0;
}
