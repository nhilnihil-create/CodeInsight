#include <iostream>
#include <iomanip>

int main() {
    int k; std::cin >> k;
    double d = (1.0 * (k / 2) + k % 2) / k;
    std::cout << std::fixed << std::setprecision(15) << d << std::endl;
    return 0;
}