#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    // 10^5回以上で偶数回移動ならば10^100回移動したのと同じ結果になる
    // RL部分に人が集まる RLでループ L|Rと境界ができる
    // 例) RRLLLL | RL | RRLL
    // ループ部分のR(L)から偶数個or奇数個離れているかで最終状態が決まる
    // ランレングス法でRのグループとLのグループを作る

    string s;
    cin >> s;

    long long size = s.size();

    vector<long long> ans(size, 0);

    // Rグループ
    long long count = 0;
    rep(i, size) {
        if (s.at(i) == 'R') {
            count++;
            continue;
        } else {
            long long even_num = count / 2;
            long long odd_num = count - even_num;
            ans.at(i) += even_num;
            ans.at(i - 1) += odd_num;
            count = 0;
        }
    }

    // Lグループ
    count = 0;
    for (long long i = size - 1; i >= 0; i--) {
        if (s.at(i) == 'L') {
            count++;
            continue;
        } else {
            long long even_num = count / 2;
            long long odd_num = count - even_num;
            ans.at(i) += even_num;
            ans.at(i + 1) += odd_num;
            count = 0;
        }
    }

    rep(i, size) {
        cout << ans.at(i) << " ";
    }
}
