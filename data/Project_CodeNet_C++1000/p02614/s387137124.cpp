#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);
    for (int i = 0; i < h; ++i) {
        cin >> c[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << h); i++) {      // Hのパターン
        for (int j = 0; j < (1 << w); j++) {  // Wのパターン
            vector<string> cp = c;
            int cnt = 0;
            for (int ii = 0; ii < h; ++ii) {
                for (int jj = 0; jj < w; ++jj) {
                    if(i & (1 << ii) || (j & (1 << jj))) {
                        cp[ii][jj] = '?';
                    }
                    if(cp[ii][jj] == '#') {
                        cnt++;
                    }
                }
            }
            ans += (cnt == k);
        }
    }

    cout << ans << endl;

    return 0;
}
