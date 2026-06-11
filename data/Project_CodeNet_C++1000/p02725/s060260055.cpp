#include <iostream>
#include <vector>

int main(void){
    int K, N, ans=0;
    std::cin >> K >> N;
    std::vector<int> A(N);

    for (int i = 0; i<N; ++i){
        std::cin >> A.at(i);
    }

    ans = A.at(0) + K - A.at(N-1);

    for (int i=1; i<N; ++i){
        int tmp = A.at(i) - A.at(i-1);
        if (tmp > ans) ans = tmp;
    }

    ans = K - ans;

    std::cout << ans << std::endl;

    return 0;
}
