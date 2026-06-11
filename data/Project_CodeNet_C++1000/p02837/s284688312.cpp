#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(15, vector<int>(15, -1));
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            --x;
            g[i][x] = y;
        }
    }
    int ans = 0;
    rep(i, 1<<n) {
        vector<bool> flg(n, false);
        rep(j, n) {
            if ((i>>j) & 1) {
                flg[j] = true;
            }
        }
        bool ok = true;
        rep(j, n) {
            if (flg[j]) {
                rep(k, n) {
                    if (g[j][k] == -1) continue;
                    if (g[j][k] != flg[k]) ok = false;
                }
            }
        }
        if (ok) ans = max(ans, __builtin_popcount(i));
    }
    cout << ans << endl;
    return 0;
}
