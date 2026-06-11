#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main(){
    string L;
    cin >> L;

    long dp[L.length() + 1][2];
    for(int i=0; i<=L.length(); i++){
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i=0; i<L.length(); i++){
        if(L[i] == '1') dp[i+1][1] = dp[i][1]*2%MOD;
        else dp[i+1][1] = dp[i][1]*1%MOD;

        dp[i+1][0] = dp[i][0]*3%MOD;
        if(L[i] == '1') dp[i+1][0] +=  dp[i][1]%MOD;

        dp[i+1][0] %= MOD;
        dp[i+1][1] %= MOD;
    }

    cout << (dp[L.length()][0] + dp[L.length()][1]) % MOD;
    return 0;
}