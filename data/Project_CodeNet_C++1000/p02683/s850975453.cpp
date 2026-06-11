#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {  // 0-index
        cin >> c.at(i);
        rep(j, m) {  // 0-index
            cin >> a.at(i).at(j);
        }
    }

    int ans = MOD;
    rep(i, 1 << n) {  // パターン
        int total = 0;
        vector<int> learned(m, 0);
        rep(j, n) {  // ビットが立っているか
            if (i >> j & 1) {
                total += c.at(j);  // 金額計算
                rep(k, m) {        // アルゴリズム理解度計算
                    learned.at(k) += a.at(j).at(k);
                }
            }
        }
        bool isAllOk = true;
        rep(l, m) {
            if (learned.at(l) < x) {
                isAllOk = false;
            }
        }
        if (isAllOk) {
            ans = min(ans, total);
        }
    }

    if (ans == MOD) ans = -1;

    cout << ans << endl;

    return 0;
}
