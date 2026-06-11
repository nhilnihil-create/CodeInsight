#include <iostream>

int main() {
    int N, X, T;
    int ans;

    std::cin >> N >> X >> T;

    ans = N / X;
    if(N % X != 0) {
        ans++;
    }
    
    std::cout << ans * T << std::endl;

    return 0;
}
