#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long mod = 1e9 + 7;
int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> use(n+1, true);

    for(long long i = 0; i < m; i++){
        long long a;
        cin >> a;
        use[a] = false;
    }

    vector<long long> dp(n+1, 0);
    dp[0] = 1;

    for(long long i = 0; i <= n; i++){
        if(i == 0) continue;
        if(i == 1){
            if(use[i] == true) dp[i] = dp[i-1];
            else dp[i] = 0;
        }
        else{
            if(use[i] == false) dp[i] = 0;
            else{
                dp[i] = dp[i-1]%mod + dp[i-2]%mod;
                dp[i] = dp[i]%mod;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}