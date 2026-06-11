#include<iostream>
#include<vector>
#include<algorithm>

int dp[3005][3005];
int main(void){
    int n, t;
    std::cin >> n >> t;
    std::vector<std::pair<int, int>> ab(n);
    for(int i = 0; i < n; i++){
        std::cin >> ab[i].first >> ab[i].second;
    }
    std::sort(ab.begin(), ab.end());
    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < t; j++){
            dp[i+1][j] = std::max(dp[i][j], dp[i+1][j]);
            int nj = j + ab[i].first;
            if(nj < t){
                dp[i+1][nj] = dp[i][j] + ab[i].second;
            }
        }
        ans = std::max(ans, dp[i][t-1] + ab[i].second);
    }
    std::cout << ans << std::endl;
    return 0;
}