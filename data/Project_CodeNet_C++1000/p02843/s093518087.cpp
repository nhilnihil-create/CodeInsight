#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;
    bool dp[100000 + 1];
    fill(dp, dp + 100000 + 1, false);

    dp[0] = true;  // 0 yen
    for (int i = 1; i <= 99; i++) {
        dp[i] = false;  // 1~99 yen
    }
    for (int i = 100; i <= 105; i++) {
        dp[i] = true;  // 100~105 yen
    }
    for (int i = 106; i <= 100000; i++) {
        for (int j = 0; j < 6; j++) {
            if (dp[i - 100 - j]) {  // Is i-100 ~ i-105 yen = true?
                dp[i] = true;       // i yen
            }
        }
    }
    if (dp[x])
        puts("1");
    else
        puts("0");
}