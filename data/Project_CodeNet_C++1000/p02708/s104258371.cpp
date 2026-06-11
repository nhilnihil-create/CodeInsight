#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    // 個数のmodを取るのであって和のmodを取るわけではない
    // 0からnまでの数の中からk個以上の数を選び和を取る
    // そのときの和の種類の個数のmodを取る

    // kからn+1を全て調べる。i, j in [k, n+1] i != j なら10^100の影響で必ず別の種類になる

    // i個取るとしたとき、最小値は小さい方からi個とった場合で最大値は大きい方からi個とった
    // 場合でその間の数値は全て作ることができる

    // 総和 後で足すたびにmodを取る
    long long ans = 0;

    // 最小値、最大値 あとで消すかも
    long long min_sum;
    long long max_sum;

    // 累積和を計算しておく
    vector<long long> cusum(n + 2, 0);
    rep(i, n + 1) {
        cusum.at(i + 1) = cusum.at(i) + i;
    }

    int right;
    int left;

    // iは選んだ数の個数 (kからn+1まで)
    for (int i = k; i < n + 2; i++) {
        right = i;
        left = 0;
        // 最小値
        min_sum = cusum.at(right) - cusum.at(left);

        right = n + 1;
        left = n - i + 1;
        // 最大値
        max_sum = cusum.at(right) - cusum.at(left);

        ans += max_sum - min_sum + 1;
        // 足すたびにMODを取る
        ans %= MOD;
    }
    cout << ans << endl;
}
