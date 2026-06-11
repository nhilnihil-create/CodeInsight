#include <iostream>
#include <vector>

int main(void){
    int N, K, Q;
    std::cin >> N >> K >> Q;
    std::vector<int> A(N, 0);

    for (int i=0; i<Q; ++i){
        int tmp;
        std::cin >> tmp;
        ++A.at(tmp - 1);
    }

    for (int i=0; i<N; ++i){
        if (A.at(i) + K > Q){
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
