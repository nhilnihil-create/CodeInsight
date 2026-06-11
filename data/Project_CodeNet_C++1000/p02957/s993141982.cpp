#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    double a, b;
    std::cin >> a >> b;
    double result = (a + b) / 2;
    
    std::cout << std::setprecision(10);
    if (std::ceil(result) == result) {
        std::cout << result << std::endl;
    } else {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
}
