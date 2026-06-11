#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) { cin >> grid.at(i); }
    vvi left(h, vi(w)), right(h, vi(w)), up(h, vi(w)), down(h, vi(w));
    rep(i, h) {
        int left_count = 0, right_count = 0;
        rep(j, w) {
            if (grid.at(i).at(j) == '.') {
                left_count++;
            } else {
                left_count = 0;
            }
            left.at(i).at(j) = left_count;
            if (grid.at(i).at(w - 1 - j) == '.') {
                right_count++;
            } else {
                right_count = 0;
            }
            right.at(i).at(w - 1 - j) = right_count;
        }
    }
    rep(j, w) {
        int up_count = 0, down_count = 0;
        rep(i, h) {
            if (grid.at(i).at(j) == '.') {
                up_count++;
            } else {
                up_count = 0;
            }
            up.at(i).at(j) = up_count;
            if (grid.at(h - 1 - i).at(j) == '.') {
                down_count++;
            } else {
                down_count = 0;
            }
            down.at(h - 1 - i).at(j) = down_count;
        }
    }
    int ans = 0;
    rep(i, h) {
        rep(j, w) { ans = max(ans, up.at(i).at(j) + down.at(i).at(j) + left.at(i).at(j) + right.at(i).at(j) - 3); }
    }
    cout << ans << endl;
}
