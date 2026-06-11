#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<string>> c(h, vector<string>(w));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            c.at(i).at(j) = s[j];
        }
    }

    // 白と黒の総数
    int black_sum = 0;
    int white_sum = 0;

    rep(i, h) {
        rep(j, w) {
            // 黒
            if (c.at(i).at(j) == "#")
                black_sum += 1;
        }
    }
    white_sum += h * w - black_sum;

    int ans = 0;

    // 行と列の選び方は2^6 * 2^6通りある
    for (int bit_i = 0; bit_i < (1 << h); bit_i++) {
        for (int bit_j = 0; bit_j < (1 << w); bit_j++) {
            // 黒の数
            int count = 0;

            // 全てのi行j列目の要素について考える
            rep(column, h) {
                rep(row, w) {
                    // 片方でもbitが立っているなら含めない
                    if ((bit_i & (1 << column)) && (bit_j & (1 << row))) {
                        // 黒なら追加
                        if (c.at(column).at(row) == "#") {
                            count++;
                        }
                    }
                }
            }

            // 黒の数がkと等しければok
            if (count == k) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
