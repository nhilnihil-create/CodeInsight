#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    // n番目の町の転移先の配列
    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
        // 0-indexで考える
        a.at(i)--;
    }

    // ループが発生するため、それを利用する
    // ただしループ前にk回転移することもある

    // ループ部分
    deque<int> loop;
    // 一度来た町かどうか
    vector<bool> visited(n, false);
    // 現在の町
    int current = 0;

    while (true) {
        // 現在の町が既に訪れた町であった場合
        if (visited.at(current)) {
            // ループ開始地点までloopを前から消去
            while (loop.at(0) != current) {
                k--;
                loop.pop_front();

                // ループ前にk回転移したらそこで終わり
                if (k == 0) {
                    cout << loop.at(0) + 1 << endl;
                    return 0;
                }
            }
            // ここにbreakを入れないと終わらない
            break;
        }

        // ループが見つかるまでの処理

        // 現在の町をループ部分に追加
        loop.push_back(current);
        // 現在の町を訪れたことにする
        visited.at(current) = true;
        // 次の町に転移
        current = a.at(current);
    }

    // k >= ループ開始地点までの転移回数 のとき
    // ループ開始地点から (k % loop.size) 回転移したところが答え
    cout << loop.at(k % loop.size()) + 1 << endl;
}
