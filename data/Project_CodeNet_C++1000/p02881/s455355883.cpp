#include <iostream>
#include <cmath>
#include <algorithm>

int main(void){
    long long N, rtN, ans=1e12+1;
    std::cin >> N;
    rtN = std::sqrt(N);

    for (int i=1; i<=rtN; ++i){
        if (N % i == 0){
            long long j = N / i;
            ans = std::min(ans, i + j - 2);
        }
    }
    
    std::cout << ans << std::endl;

    return 0;
}
