#include <algorithm>
#include <iostream>
#include <vector>

using ui_vec = std::vector<unsigned int> ;

int main()
{
    constexpr unsigned int MOD = 998'244'353 ;

    //inputs
    unsigned int N, S ;
    std::cin >> N >> S ;

    ui_vec A(N + 1, 0) ;
    for(unsigned int i = 1 ; i <= N ; i ++) {
        std::cin >> A[i] ;
    }

    std::vector<ui_vec> dp(N + 1, ui_vec(S + 1, 0)) ;
    dp[0][0] = 1 ;

    for(unsigned int i = 1 ; i <= N ; i ++) {
        for(unsigned int s = 0 ; s <= S ; s ++) {
            dp[i][s] += 2 * dp[i - 1][s] ; //pull above

            if(s >= A[i]) {
                dp[i][s] += dp[i - 1][s - A[i]] ; // pull left upper
            }

            dp[i][s] %= MOD ;
        }
    }

    std::cout << dp[N][S] << std::endl ;
    return 0 ;
}