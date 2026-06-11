#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

const int MOD = 1000000007;

int main(){
    int s;
    std::cin >> s;

    std::vector<int> dp(s + 1);
    dp[0] = 1;

    for (int i = 3; i <= s; i++)
    {
        dp[i] = (dp[i - 3] + dp[i - 1]) % MOD;
    }
    
    std::cout << dp[s] << std::endl;

    return 0;
}