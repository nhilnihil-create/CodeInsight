#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c[i][j];
        }
    }
    int ans = 0;
    for (int bit1 = 0; bit1 < (1 << h); bit1++) {
        for (int bit2 = 0; bit2 < (1 << w); bit2++) {
            int black = 0;
            for (int i = 0; i < h; i++) {
                if (bit1 & (1 << i)) {
                    continue;
                }
                for (int j = 0; j < w; j++) {
                    if (bit2 & (1 << j)) {
                        continue;
                    }
                    if (c[i][j] == '#') {
                        black++;
                    }
                }
            }
            if (black == k) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}