//https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_A

#include <bits/stdc++.h>

using namespace std;

int coin_change(const int coins[], int cn, int money) {
    int table[money + 1];
    table[0] = 0;

    int pred[money + 1];
    for (int i = 0; i <= money; i++) {
        pred[i] = 0;
    }

    for (int j = 1; j <= money; j++) {
        table[j] = INT_MAX;
    }

    for (int i = 1; i <= money; i++) {
        int mini = table[i];
        for (int j = 0; j < cn; j++) {
            if (i >= coins[j]) {
                mini = min(mini, table[i - coins[j]] + 1);
                pred[i] = j;
            }
        }
        table[i] = mini;
    }

    return table[money];
}


int main() {
    int n, m;
    cin >> n >> m;

    int coins[m];
    for (int i = 0; i < m; ++i) {
        cin >> coins[i];
    }

    cout << coin_change(coins, m, n) << endl;
    return 0;
}

/*
 * spaghetti-sourceのコードを利用。
 *
 */
