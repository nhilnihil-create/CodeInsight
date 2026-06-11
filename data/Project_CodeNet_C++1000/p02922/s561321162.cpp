#include <iostream>

int main() {
    auto ceildiv = [](auto a, auto b) { return ((a + b - 1) / b); };

    int a, b;
    std::cin >> a >> b;

    std::cout << ceildiv(b-1, a-1);
}