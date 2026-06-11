#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>

int main(){
    int n;
    std::cin >> n;

    std::cout << std::fixed << std::setprecision(10) << (double)(n - n / 2) / n << std::endl;

    return 0;
}