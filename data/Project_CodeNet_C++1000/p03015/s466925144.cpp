#include <iostream>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;

int main(){
    string L;
    cin >> L;

    long dp[L.length()][2][2];
    for(int i=0; i<L.length(); i++){
        for(int j=0; j<2; j++){
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    dp[0][1][1] = 2;
    dp[0][0][0] = 1;
    
    for(int i=0; i<L.length()-1; i++){
        if(L[i+1] == '0'){
            dp[i+1][0][1] = max(dp[i][0][1], dp[i][1][1]);
        }else{
            dp[i+1][1][1] = max(dp[i][0][1], dp[i][1][1])*2;
            dp[i+1][1][1] %= MOD;
            dp[i+1][0][0] += max(dp[i][0][1], dp[i][1][1]);
            dp[i+1][0][0] %= MOD;
        }
        dp[i+1][0][0] += dp[i][0][0] + dp[i][1][0];
        dp[i+1][0][0] %= MOD;
        dp[i+1][1][0] += (dp[i][0][0] + dp[i][1][0])*2;
        dp[i+1][1][0] %= MOD;
    }

    long ans = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ans += dp[L.length()-1][i][j];
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
