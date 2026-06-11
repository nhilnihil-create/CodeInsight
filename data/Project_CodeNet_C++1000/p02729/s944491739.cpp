#include <iostream>

int n, m;

int main() {
    std::cin >> n >> m;
    std::cout << (n * (n-1) / 2) + (m * (m-1) / 2);
}