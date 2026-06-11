#include<iostream>
#include<vector>
#include<algorithm>


const int MOD = 1e9+7;

int main(void){
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    std::vector<long long> dp(13);
    int mul = 1;
    dp[0] = 1;
    for(int i = 0; i < s.size(); i++){
        std::vector<long long> dp_next(13);
        if(s[i] == '?'){
            for(int j = 0; j < 13; j++){
                for(int k = 0; k < 10; k++){
                    dp_next[(mul * k + j) % 13] += dp[j] % MOD;
                }
            }
        }else{
            for(int j = 0; j < 13; j++){
                dp_next[(mul * (s[i] - '0') + j) % 13] += dp[j] % MOD;
            }
        }
        mul = (mul * 10) % 13;
        std::swap(dp, dp_next);
    }
    std::cout << dp[5] % MOD << std::endl;
    return 0;
}