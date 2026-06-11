#include <iostream>

int main() {
    long x[2], y[2];

    for(int i = 0; i < 2; ++i) {
        std::cin >> x[i];
    }

    for(int i = 0; i < 2; ++i) {
        std::cin >> y[i];
    }

    long long p = -1e18;

    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            if(x[i] * y[j] > p) {
                p = x[i] * y[j];
            }
        }
    }

    std::cout << p << "\n";
}