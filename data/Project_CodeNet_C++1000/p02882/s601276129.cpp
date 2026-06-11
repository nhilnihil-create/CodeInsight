#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>

int main(void){
    double a, b, x;
    std::cin >> a >> b >> x;
    // if(b - sta::tan())
    double tan = 2 / std::pow(a, 3) * (std::pow(a, 2) * b - x);
    // std::cout << a * std::tan(ans) << std::endl;
    if(tan <= b / a) {
        std::cout << std::fixed << std::setprecision(15) << std::atan2(tan, 1) * 180 / M_PI << std::endl;
    }else{
        tan = std::pow(b, 2) / (2 * x ) * a;
        std::cout << std::fixed << std::setprecision(15) << std::atan2(tan, 1) * 180 / M_PI << std::endl;
    }
    // std::cout << ans * 180 / M_PI << std::endl;
    // std::cout << std::tan(ans) << std::endl;
    return 0;
}
