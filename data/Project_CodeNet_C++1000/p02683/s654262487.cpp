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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {
        cin >> c[i];
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    int ans = 1e8;
    rep(i, 1<<n) {
        vector<int> b(m, 0);
        int cost = 0;
        rep(j, n) {
            if ((i>>j) & 1) {
                cost += c[j];
                rep(k, m) {
                    b[k] += a[j][k];
                }
            }
        }
        bool ok = true;
        rep(k, m) {
            if (b[k] < x) ok = false;
        }
        if (ok) {
            ans = min(ans, cost);
        }
    }
    if (ans == 1e8) cout << -1 << endl;
    else            cout << ans << endl;
    return 0;
}
