#include <iostream>
using i64 = long long;

int main() {
    int d, s, t;
    std::cin >> d >> s >> t;
    std::cout << (d <= s * t ? "Yes" : "No") << std::endl;

    return 0;
}
