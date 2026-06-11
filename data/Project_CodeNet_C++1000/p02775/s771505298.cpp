#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <complex>
typedef long long int LL;
using namespace std;

// 插入此處

int dp[1000006][2];

int main() {
    string s;
    cin >> s;
    int len = s.size();
    dp[0][1] = 1;
    for (int i = 0; i < len; i++) {
        int x = s[i] - '0';
        dp[i + 1][0] = min(dp[i][0] + x, dp[i][1] + 10 - x);
        dp[i + 1][1] = min(dp[i][0] + x + 1, dp[i][1] + 9 - x);
    }
    cout << dp[len][0] << endl;
}
