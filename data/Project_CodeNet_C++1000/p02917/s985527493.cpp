#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, ans=0;
    std::cin >> N;
    std::vector<int> B(N);
    for (int i=0; i<N-1; ++i){
        std::cin >> B.at(i);
    }
    
    ans += B.at(0);
    
    for (int i=1; i<N-1; ++i){
        ans += std::min(B.at(i-1), B.at(i));
    }

    ans += B.at(N-2);

    std::cout << ans << std::endl;

    return 0;
}
