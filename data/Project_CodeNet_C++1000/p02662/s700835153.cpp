#include <bits/stdc++.h>

int mod = 998244353;

int main(){
    int N, S;
    std::cin >> N >> S;
    std::vector< int > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    std::vector< std::vector< long long > > dp(N+1, std::vector< long long >(S+1, 0));
    for(int i=1; i<=N; i++){
        for(int j=0; j<=S; j++){
            dp[i][j] = (2 * dp[i-1][j]) % mod;
            if(j >= A[i-1]){
                dp[i][j] = (dp[i][j] + dp[i-1][j-A[i-1]]) % mod;
            }
            if(j == 0 || j == A[i-1]){
                dp[i][j] = (dp[i][j] + 1) % mod;
            }
        }
        //for(int j=0; j<=S; j++){
        //    std::cout << dp[i][j] << " ";
        //}
        //std::cout << std::endl;
    }
    
    std::cout << dp[N][S] << std::endl;;
    
    
    return 0;
    
}
