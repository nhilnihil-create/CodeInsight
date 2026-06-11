#include <iostream>

int main(void){
    long long N, K;
    std::cin >> N >> K;

    long long ans = N;

    if (ans >= K) ans %= K;
    if (ans > K - ans) ans = K - ans;

    std::cout << ans << std::endl;

    return 0;
}
