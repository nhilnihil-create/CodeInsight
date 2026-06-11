#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t>dp(N+1, 0);
    for (int64_t i=0; i<M; i++) {
        int64_t num;
        cin >> num;
        dp[num] = -1;
    }

    dp[0] = 1;
    for (int64_t i=1; i<=N; i++) {
        if (dp[i] == -1) continue;
        int64_t pattern = 0;
        if (dp[i-1] != -1) pattern += dp[i-1];
        if (i > 1 && dp[i-2] != -1) pattern += dp[i-2];
        dp[i] = pattern % 1000000007;
    }

    cout << dp[N] << endl;
    return 0;
}