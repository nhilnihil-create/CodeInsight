#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    double r;
    std::cin >> r;
    std::cout << std::fixed << std::setprecision(6) << M_PI*r*r << " " << M_PI*2*r << "\n";
    return 0;
}