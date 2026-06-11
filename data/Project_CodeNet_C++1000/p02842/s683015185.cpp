#include <iostream>

int main() {
    int n;
    std::cin >> n;

    bool found = false;
    for (int i = 1; i <= 50000; i++) {
        if ((int)(i * 1.08) == n) {
            std::cout << i << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << ":(" << std::endl;
    }

    return 0;
}