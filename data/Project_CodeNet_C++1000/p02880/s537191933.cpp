#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int N; std::cin >> N;
    for (auto i{ 1 }; i < 10; ++i)
        for (auto j{ 1 }; j < 10; ++j)
            if (i * j == N) {
                std::cout << "Yes";
                return 0;
            }

    std::cout << "No" << std::endl;
    return 0;
}
