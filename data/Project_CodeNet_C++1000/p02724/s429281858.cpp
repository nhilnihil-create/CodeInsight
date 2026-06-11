#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

int main(){
    int x;
    std::cin >> x;

    int a = x / 500;
    int b = (x - a * 500) / 5;
    
    std::cout << a * 1000 + b * 5 << std::endl;

    return 0;
}