#include <iostream>
#include <algorithm>

int main() {
    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::cout << std::max({ a * c, a * d, b * c, b * d }) << '\n';
}
