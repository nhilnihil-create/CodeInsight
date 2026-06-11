//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
    
    long long int i,j,s;
    cin >> s;
    long long int dp[s+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(i = 1;i<=s;i++){
        for(j = 3;j<=s;j++){
            if(i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
      cout << dp[s] << endl;
    return 0;
}