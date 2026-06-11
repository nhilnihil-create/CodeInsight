#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    rep (i, 0, h) rep (j, 0, w) cin >> grid[i][j];
    int cnt[h][w];
    rep (i, 0, h) rep (j, 0, w) cnt[i][j] = 0;
    int cnt2[h][w];
    rep (i, 0, h) rep (j, 0, w) cnt2[i][j] = 0;
    rep (i, 0, h) {
        int sum = 0;
        rep (j, 0, w) {
            if (grid[i][j] == '.') cnt[i][j] = ++sum;
            else {
                sum = 0;
            }
        }
        per (j, 0, w) {
            if (grid[i][j] == '.' && j + 1 < w)
                cnt[i][j] = max (cnt[i][j + 1], cnt[i][j]);
        } /*
         rep (j, 0, w) { cout << cnt[i][j]; }
         cout << "\n";*/
    }
    rep (j, 0, w) {
        int sum = 0;
        rep (i, 0, h) {
            if (grid[i][j] == '.') cnt2[i][j] = ++sum;
            else {
                sum = 0;
            }
        }
        per (i, 0, h) {
            if (grid[i][j] == '.' && i + 1 < h)
                cnt2[i][j] = max (cnt2[i + 1][j], cnt2[i][j]);
        }
    } /*
     cout << "\n";
     rep (i, 0, h) {
         rep (j, 0, w) cout << cnt2[i][j];
         cout << "\n";
     }*/
    int ans = 0;
    rep (i, 0, h) rep (j, 0, w) ans = max (ans, cnt[i][j] + cnt2[i][j] - 1);
    cout << ans << "\n";
}