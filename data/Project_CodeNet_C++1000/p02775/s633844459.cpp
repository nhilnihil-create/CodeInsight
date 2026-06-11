#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    reverse(S.begin(),S.end());
    S = S + string(1e+6+10,'0');
    
    vector<vector<int64_t>> dp(2,vector<int64_t>(1e+6+10,0));
    dp[0][0] = 0;
    dp[1][0] = 1 << 30;
    
    for ( int64_t i = 0; i < 1e+6+10; ++i){
        dp[0][i+1] = min( dp[0][i] + (S[i]-'0'), dp[1][i] + (S[i]-'0'+1) );
        dp[1][i+1] = min( dp[0][i] + 10 - (S[i]-'0'), dp[1][i] + 10 - (S[i]-'0'+1));
    }
    
    cout << dp[0][1e+6+5] << endl;
    
    return 0;
}
