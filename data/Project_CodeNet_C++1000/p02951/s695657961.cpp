#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    std::cout << C - std::min(A - B, C) << "\n";
}