#include <iostream>

int main() {
    int A, B, K;

    std::cin >> K;
    std::cin >> A >> B;

    for(int i = A; i <= B; i++) {
        if(i % K == 0) {
            std::cout << "OK" << std::endl;
            return 0;
        }
    }

    std::cout << "NG" << std::endl;

    return 0;
}
