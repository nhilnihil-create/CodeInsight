#include <iostream>
int main() {
    int a, b, c, d = 0;
    std::cin >> a >> b >> c;
    for (int i = a; i <= b; ++i) {
        if (c % i == 0) {
            ++d;
        }
    }
    std::cout << d << std::endl;
}

