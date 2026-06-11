#include <iostream>
#include <math.h>

int main(int argc, char const *argv[]) {
    double r;

    std::cin >> r;
    std::cout << std::fixed << M_PI * r* r <<  " " << std::fixed << M_PI * 2 * r << std::endl;

    return 0;
}