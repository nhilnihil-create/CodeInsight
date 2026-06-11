#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << std::fixed << std::setprecision(6) << std::sqrt(std::pow(x1-x2, 2) + std::pow(y1-y2, 2)) << "\n";
    return 0;
}