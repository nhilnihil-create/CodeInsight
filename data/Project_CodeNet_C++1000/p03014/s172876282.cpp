#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];
    vector<vector<int>> l(H, vector<int>(W)), r(H, vector<int>(W)),
        u(H, vector<int>(W)), d(H, vector<int>(W));
    rep(i, H) {
        int tmp = 0;
        rep(j, W) {
            if(grid[i][j] == '#') {
                l[i][j] = INF;
                tmp = 0;
            } else {
                l[i][j] = tmp;
                tmp++;
            }
        }
    }
    rep(i, H) {
        int tmp = 0;
        for(int j = W - 1; j >= 0; j--) {
            if(grid[i][j] == '#') {
                r[i][j] = INF;
                tmp = 0;
            } else {
                r[i][j] = tmp;
                tmp++;
            }
        }
    }
    rep(j, W) {
        int tmp = 0;
        rep(i, H) {
            if(grid[i][j] == '#') {
                u[i][j] = INF;
                tmp = 0;
            } else {
                u[i][j] = tmp;
                tmp++;
            }
        }
    }
    rep(j, W) {
        int tmp = 0;
        for(int i = H - 1; i >= 0; i--) {
            if(grid[i][j] == '#') {
                d[i][j] = INF;
                tmp = 0;
            } else {
                d[i][j] = tmp;
                tmp++;
            }
        }
    }
    int res = 0;
    rep(i, H) rep(j, W) {
        res = max(res, l[i][j] + r[i][j] + u[i][j] + d[i][j] + 1);
    }
    cout << res << endl;
    return 0;
}