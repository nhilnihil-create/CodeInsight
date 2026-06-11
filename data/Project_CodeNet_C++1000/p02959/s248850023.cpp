#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    long long N, ans=0;
    std::cin >> N;
    std::vector<long long> A(N + 1);

    for (int i=0; i<N+1; ++i){
        std::cin >> A.at(i);
    }

    for (int i=0; i<N; ++i){
        long long b, tmp;
        std::cin >> b;
        tmp = A.at(i) - b;
        if (tmp < 0){
            ans += A.at(i);
            if (A.at(i + 1) + tmp < 0){
                ans += A.at(i + 1);
                A.at(i + 1) = 0;
            } else {
                ans += -tmp;
                A.at(i + 1) += tmp;
            }
        } else {
            ans += b;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
