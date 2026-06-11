#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

// 最大のkに対する答えが10桁より、最大でも10桁のルンルン数を列挙すればよい
// DFSで全列挙しソートしてk番目を出力

// 桁数、現在の値、ルンルン数
void dfs(int d, long long v, vector<long long> &lunlun_num) {
    // 現在の値を格納
    lunlun_num.push_back(v);

    // 11桁以上は探索しない
    if (d == 10) return;

    // 次の桁を探索
    for (int i = -1; i <= 1; i++) {
        // 一桁目の数字を見て、それの-1, +0, +1したときの値を後ろにくっつける
        int addition = (v % 10) + i;
        // -1や10は後ろに付与しない
        if (addition >= 0 && addition <= 9) {
            dfs(d + 1, v * 10 + addition, lunlun_num);
        }
    }
}

int main() {
    int k;
    cin >> k;

    // ルンルン数
    vector<long long> lunlun_num;

    // 1から9までで10桁まで探索
    for (int v = 1; v < 10; v++) {
        dfs(1, v, lunlun_num);
    }

    // 小さい順に並び替える
    sort(lunlun_num.begin(), lunlun_num.end());
    // K番目
    cout << lunlun_num.at(k - 1) << endl;
}
