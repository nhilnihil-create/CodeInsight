// ABC169-F Knapsack for All Subsets

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int N, S, A[3000];
    cin >> N >> S;

    vector<vector<long long>> dp(N+1, vector<long long>(S+1, 0));
    // dp[i][j] := 最初のi個の数のみついて考えたとき、総和がjであるように選んでできる部分集合全てについての、それを含むような集合の総和

    for (int i=0 ;i<N ;i++ ) {
        cin >> A[i];
    }

    dp[0][0] = 1; 

    for (int i=0 ;i<N ;i++ ) {
        for (int j=0 ;j<=S ;j++ ) {
            dp[i+1][j] += dp[i][j] * 2 % MOD;

            if (j-A[i] >= 0) {
                dp[i+1][j] += dp[i][j-A[i]];
            }
            dp[i+1][j] %= MOD;
        }
    }

    cout << dp[N][S] << '\n';
}