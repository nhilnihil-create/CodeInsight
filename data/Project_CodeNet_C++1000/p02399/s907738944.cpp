#include <iostream>
#include <iomanip>
int main() {
    long a, b;
    std::cin >> a >> b;
    std::cout << a / b << ' ' << a % b << ' ';
    std::cout << std::fixed << std::setprecision(6)
        << static_cast<double>(a) / b << std::endl;
}

