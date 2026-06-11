#include<iostream>

int dp[5005][5005];

int main(void){
    int n;
    std::string s;
    std::cin >> n >> s;
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(s[i] != s[j]) continue;
            dp[i][j] = dp[i+1][j+1] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int cur = std::min(dp[i][j], j-i);
            ans = std::max(ans, cur);
        }
    }
    std::cout << ans << std::endl;

    return 0;
}