#include <algorithm>
#include <cmath>
#include <iostream>

int a, b;

int main() {
    std::cin >> a >> b;
    for (int i = 1; i <= 1000; i++) {
        int a2 = i * 0.08;
        int b2 = i * 0.1;
        if (a2 == a && b2 == b) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
}
