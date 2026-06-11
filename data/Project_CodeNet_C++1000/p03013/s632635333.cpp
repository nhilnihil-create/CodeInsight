#include <iostream>
#include <vector>
using namespace std;



int main(){
    long long int n, m;
    cin >> n >> m;
    vector<long long int> dp(n+1, -1);
    dp[0] = dp[1] = 1;
    
    for (long long int i = 0; i < m; i++){
        long long int  peldano; cin >> peldano;
        dp[peldano] = 0;
    }
    
    for (long long int  i = 2; i <= n; i++){
        if (dp[i] != 0) dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }

    cout << dp[n] << endl;
    return 0;
}

