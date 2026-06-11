#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    // 右側から見ていくとかならずいいボールの入れ方が存在することが分かる
    // (i) iの倍数がないとき
    // a=1 => ボールを入れる
    // a=0 => ボールは入れない
    // (ii) iの倍数があるとき
    // 自身を除く倍数のボールの数が奇数個
    // & a=1 => ボールは入れない
    // & a=0 => ボールを入れる
    // 偶数個ならばボールを入れる入れないを逆転する

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }

    // ボールが入っているかどうか
    vector<bool> ball(n, false);
    // ボールを入れた箱の番号を記録
    vector<int> in_ball;
    long long ball_num = 0;

    // 後ろから見ていく(n~1)
    for (int i = n; i >= 1; i--) {
        // 自身を除く倍数のボールが何個かを数える
        int count = 0;
        for (int j = 2 * i; j <= n; j += i) {
            // indexは-1する
            if (ball.at(j - 1) == true) {
                count++;
            }
        }

        // 倍数なしのときも含む
        // 偶数個でa=1のときと奇数個でa=0のときボールを入れる
        if ((count % 2 == 0 && a.at(i - 1) == 1) || (count % 2 == 1 && a.at(i - 1) == 0)) {
            ball.at(i - 1) = true;
            // ボールを入れる場合その箱の番号を記録
            in_ball.push_back(i);
            ball_num++;
        }
    }

    cout << ball_num << endl;
    for (auto v : in_ball) {
        cout << v << " ";
    }
}
