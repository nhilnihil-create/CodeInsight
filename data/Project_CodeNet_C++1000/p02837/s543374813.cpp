#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    vector<vector<int>> c(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y; cin >> x >> y;
            c[i][--x] = y;
        }

    }
    int ans = 0;  
    for (int bit = 0; bit < (1 << n); ++bit) {
        int cnt = 0;
        vector<bool> honest(n, false);
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                honest[i] = true;
                cnt++;
            }

        }
        // 矛盾をチェック
        bool can = true;
        for (int i = 0; i < n; i++) {
            if (honest[i]) {
                for (int j = 0; j < n; j++) {
                    if ((c[i][j] == 1 && !honest[j]) || (c[i][j] == 0 && honest[j])) {
                        can = false;
                    }
                }
            }
        }
        if (can) ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}