#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }

    // ソートする
    sort(a.begin(), a.end());

    // A_maxの値
    int a_max = a.at(n - 1);

    // 1からA_maxまでの条件を満たすかの配列
    // i番目より小さいiの約数がAに存在しないことを表す
    vector<bool> qualified(a_max, true);

    // 各Aの要素について倍数を全てfalseにする
    // 計算量解析によるとO(A_max log A_max)時間
    rep(i, n) {
        // Aのi番目の要素の値
        int a_i = a.at(i);

        // 条件を満たさないものの倍数は既に条件を満たさないことになっている
        if (qualified.at(a_i - 1) == false) continue;

        // 2個前と同じならば既に処理は完了している
        if (i >= 2) {
            if (a_i == a.at(i - 2)) {
                continue;
            }
        }

        //1個前と同じやつだったら自分自身も条件を満たさない
        if (i >= 1) {
            if (a_i == a.at(i - 1)) {
                qualified.at(a_i - 1) = false;
            }
        }

        //1以上の数でA_maxまでで調べる(a_iはカウントしない)
        for (int x = 2 * a_i; x < a_max + 1; x += a_i) {
            // 倍数xは条件を満たさない
            qualified.at(x - 1) = false;
        }
    }

    int ans = 0;

    // 二部探索でAの要素が条件を満たすかを確認する
    for (int a_i : a) {
        // a_iがtrueであれば答えに1をプラスする
        if (qualified.at(a_i - 1)) ans++;
    }

    cout << ans << endl;
}
