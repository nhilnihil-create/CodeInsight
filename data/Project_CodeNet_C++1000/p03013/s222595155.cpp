#include<iostream>
#include<vector>
#include<string>

const int MOD = 1000000007;

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<bool> notUsed(n + 1, false);
    for(int i = 0; i < m; i++){
        int a;
        std::cin >> a;
        notUsed[a] = true;
    }

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        // 現在i段目にいる
        if(i + 1 <= n && !notUsed[i + 1]){
            dp[i + 1] += dp[i];
            dp[i + 1] %= MOD;
        }
        if(i + 2 <= n && !notUsed[i + 2]){
            dp[i + 2] += dp[i];
            dp[i + 2] %= MOD;
        }
    }

    std::cout << dp[n] % MOD << std::endl;
    return 0;
}
