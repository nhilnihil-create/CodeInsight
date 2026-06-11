#include <iostream>
#include <string>

int main() {
    std::string S;
    int K;

    std::cin >> K;
    std::cin >> S;

    if(S.size() <= K) {
        std::cout << S << std::endl;
    }
    else {
        for(int i = 0; i < K; i++) {
            std::cout << S.at(i);
        }
        std::cout << "..." << std::endl;
    }

    return 0;
}
