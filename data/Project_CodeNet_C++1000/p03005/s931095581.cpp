#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::cout << ((K == 1) ? (0) : (N - K)) << std::endl;
}