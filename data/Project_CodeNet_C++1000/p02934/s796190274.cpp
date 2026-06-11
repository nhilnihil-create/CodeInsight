#include <iostream>
#include <iomanip>

int main() {
    int n; std::cin >> n;
    double d = 0;
    for (int i = 0; i < n ;i++) {
        int v; std::cin >> v;
        d += (1.0/v);
    }
    std::cout << std::fixed << std::setprecision(15) << (1/d) << std::endl;
    return 0;
}