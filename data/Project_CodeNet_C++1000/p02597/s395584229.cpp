#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> c(n);
    rep(i, n) {
        c.at(i) = s[i];
    }

    // 赤い石と白い石の総数
    int red_sum = 0;
    int white_sum = 0;

    rep(i, n) {
        if (c.at(i) == "R") {
            red_sum += 1;
        }
    }
    white_sum = n - red_sum;

    // 最小操作回数
    int operation_min = INF;

    // 仕切りを左から右へずらしていく
    int left_white, right_red;
    // 仕切りが左端のとき
    left_white = 0;
    right_red = red_sum;

    // 仕切りが左端のときの判定
    if (max(left_white, right_red) < operation_min) {
        operation_min = max(left_white, right_red);
    }

    for (int i = 0; i < n; i++) {
        // 仕切りの移動と左右の石の更新
        if (c.at(i) == "R") {
            // 赤なら右の赤が1つ減る
            right_red -= 1;
        } else if (c.at(i) == "W") {
            // 白なら左の白が1つ増える
            left_white += 1;
        }

        //  最小操作の更新判定
        if (max(left_white, right_red) < operation_min) {
            operation_min = max(left_white, right_red);
        }
    }

    cout << operation_min << endl;
}
