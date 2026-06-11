//
// Created by munaiyi on 2020/3/17.
//

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
char shit[maxn];
int dp[2][maxn];

int main() {
    scanf("%s", shit);
    int l = strlen(shit);
    while (l && shit[l - 1] == '0') l--;
    dp[0][l] = 0;
    dp[1][l] = maxn;
    for (int i = l - 1; i >= 0; i--) {
        dp[0][i] = min(dp[0][i + 1], dp[1][i + 1]) + shit[i] - '0';
        dp[1][i] = min(dp[0][i + 1] + 1  + 10 - shit[i] + '0', dp[1][i + 1] + 9 - shit[i] + '0');
//        dp[1][i] = min(dp[1][i], dp[1][i + 1] + shit[i] - '0');
//        printf("%d %d %d\n", i, dp[0][i], dp[1][i]);
    }
    printf("%d\n", min(dp[0][0], dp[1][0]));
    return 0;
}