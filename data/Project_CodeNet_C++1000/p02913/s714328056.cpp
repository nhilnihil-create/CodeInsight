#include <bits/stdc++.h>

int main(){
    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector< std::vector< int > > dp(N+1, std::vector< int >(N+1, 0));

    int ans = 0;
    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>i; j--){
            if(S[i] == S[j]){
                if(dp[i][j] < dp[i+1][j+1] + 1){
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
            }
            ans = std::max(ans, std::min(dp[i][j], j-i));
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

