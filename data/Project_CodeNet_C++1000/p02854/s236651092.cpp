#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, ans = 0;
    long long total = 0, tmp = 0;
    std::cin >> N;
    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i){
        std::cin >> A[i];
        total += A[i];
    }
    for (int i = 0; i < N; ++i){
        tmp += A[i];
        if (tmp >= total / 2){
            ans = std::min(2 * tmp - total, total - 2 * (tmp - A[i]));
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
