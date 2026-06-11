#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;

    // mod kによってk個のグループに分ける
    // 各グループに対してそのグループにおいて最大何点とれるかを求める
    // ただし連続で同じ手を出すことはできない

    // 貪欲法で解く(確認済み)
    // 基本的には勝てる手を出し、1つ前に出した手のせいで勝てないときは飛ばす(手をリセット)

    long long score = 0;

    // グループ毎に
    for (int i = 0; i < k; i++) {
        // 各グループにおいて
        // 前回の手(初期値は適当なchar)
        char pre_hand = 'a';

        for (int j = i; j < n; j += k) {
            // 今回の敵の手
            char hand = t.at(j);

            // 前回の手と同じ場合は点数なし
            if (hand == pre_hand) {
                // 前回の手を初期化
                pre_hand = 'a';
                continue;
            }

            // 前回の手と異なる場合点数を加算
            if (hand == 'r') {
                score += p;
            } else if (hand == 's') {
                score += r;
            } else if (hand == 'p') {
                score += s;
            }

            // 今回の手を更新
            pre_hand = hand;
        }
    }

    cout << score << endl;
}
