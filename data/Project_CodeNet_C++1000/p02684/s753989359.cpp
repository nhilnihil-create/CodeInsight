// 　　＿＿
// 　／　<＠ﾌ
//  ｜(ﾉﾉハ))
//  ﾉ从ﾟヮﾟ从
// 　ﾉ｜ｿﾉГ|つ author:hotarunx
// 〈_ﾉ^^^ヽ|
// 　~~tｧtｧ~
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Aを0-basedに変換
    for (auto &&i : a) {
        i--;
    }

    int log_k = 1;
    while ((1LL << log_k) < m) log_k++;

    // next[k][i]: i番目の要素の2^k個次の要素
    vector<vector<int>> next(log_k, vector<int>(n, 0));
    next[0] = a;

    for (int k = 0; k < log_k - 1; k++) {
        for (int i = 0; i < n; i++) {
            next[k + 1][i] = next[k][next[k][i]];
        }
    }

    int p = 0;
    for (int k = 0; k < log_k; k++) {
        if (m & (1LL << k)) p = next[k][p];
    }

    cout << p + 1 << "\n";
}
