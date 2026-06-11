#include <bits/stdc++.h>
 
using namespace std;

using usize = ::std::size_t;
using u64 = ::std::uint_least64_t;
u64 N;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;
vector<u64> rows(110), columns(110);
vector<vector<u64>> dp(110, vector<u64> (110, -1));

u64 mcm(u64 i, u64 j){
    if (~dp[i][j]) {
        return dp[i][j];
    }
    dp[i][j] = Inf;
    if (i == j) {
        dp[i][j] = 0;
    } else {
        for (u64 k = i; k < j; k++) {
            dp[i][j] = min(dp[i][j], mcm(i, k) + mcm(k + 1, j) + rows[i] * columns[k] * columns[j]);
        }
    }
    return dp[i][j];
}

int main(int argc, char *argv[])
{
    
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    
    for (int i = 0; i < N; i++) {
        cin >> rows[i] >> columns[i];
    }
    
    cout << mcm(0, N - 1) << endl;
    
    return 0;
}

