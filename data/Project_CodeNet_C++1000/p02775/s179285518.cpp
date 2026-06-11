#include <bits/stdc++.h>

int main(){
    std::string N;
    std::cin >> N;
    
    std::vector< std::vector< int > > dp(N.size()+1, std::vector< int >(2, 0));
    dp[0][1] = 1;
    for(int i=0; i<N.size(); i++){
        int tmp = N[i] - '0';
        int pat00 = tmp;
        int pat01 = tmp + 1;
        int pat10 = 10 - tmp;
        int pat11 = 10 - tmp - 1;
        if(i == N.size() - 1){
            dp[i+1][0] = dp[i][0] + pat00;
            dp[i+1][1] = dp[i][1] + pat10;
        }else{
            if(dp[i][0] + pat00 > dp[i][1] + pat10){
                dp[i+1][0] = dp[i][1] + pat10;
            }else{
                dp[i+1][0] = dp[i][0] + pat00;
            }
    
            if(dp[i][0] + pat01 > dp[i][1] + pat11){
                dp[i+1][1] = dp[i][1] + pat11;
            }else{
                dp[i+1][1] = dp[i][0] + pat01;
            }
        }
    }

    if(dp[N.size()][0] > dp[N.size()][1]){
        std::cout << dp[N.size()][1] << std::endl;
    }else{
        std::cout << dp[N.size()][0] << std::endl;
    }
    
    return 0;
}

