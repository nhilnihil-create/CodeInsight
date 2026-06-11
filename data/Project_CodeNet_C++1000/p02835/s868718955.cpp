#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << ((a + b + c >= 22)? "bust":"win") << std::endl;

    return 0;
}