#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200010;
int dp[MAX_N][2];
char S[MAX_N];
// dp[i][0] := i文字目まで確定したときに、直前の部分文字列が1文字である場合の最大分割数
// dp[i][1] := i文字目まで確定したときに、直前の部分文字列が2文字である場合の最大分割数
// dp[0][0] = 1, dp[0][1] = 0, dp[1][1] = 1;
// dp[1][0] = (S[1] != S[0]) ? 2: 0;
// (dp[i-1][0]からの遷移)
// if(S[i] != S[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][0] + 1);
// dp[i+1][1] = max(dp[i+1][1], dp[i-1][0] + 1);
// (dp[i-1][1]からの遷移)
// dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
// if(S[i-2] != S[i] || S[i-1] != S[i+1]) dp[i+1][1] = max(dp[i+1][1], dp[i-1][1] + 1);

int main() {
    scanf("%s",S);
    int n = strlen(S);
    dp[0][0] = 1, dp[1][1] = 1;
    for(int i = 0; i + 1 < n; ++i) {
        if(S[i] != S[i+1]) dp[i+1][0] = max(dp[i+1][0], dp[i][0] + 1);
        if(i+2 < n) dp[i+2][1] = max(dp[i+2][1], dp[i][0] + 1);

        dp[i+1][0] = max(dp[i+1][0], dp[i][1] + 1);
        if(i+2 < n && i-1 > 0 && (S[i-1] != S[i+1] || S[i] != S[i+2])) 
            dp[i+2][1] = max(dp[i+2][1], dp[i][1] + 1);
    }
    printf("%d\n", max(dp[n-1][0], dp[n-1][1]));
    return 0;
}