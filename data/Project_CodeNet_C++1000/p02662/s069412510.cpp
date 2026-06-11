#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
using ll = long long;

const long long MOD = 998244353;

int main(){
    int N, S;
    std::cin >> N >> S;

    std::vector<int> A;
    for(int i=0; i<N; i++){
        int b; std::cin >> b; A.push_back(b);
    }

    std::vector<std::vector<ll>> dp(N+1, std::vector<ll>(S+1, 0));
    dp[0][0] = 1;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<S+1; ++j) {
            dp[i+1][j] += dp[i][j]*2%MOD;
            if (j+A[i] <= S) {
                dp[i+1][j+A[i]] += dp[i][j]%MOD;
            }
        }
    }

    std::cout << (dp[N][S]+MOD)%MOD;
    return 0;
}
