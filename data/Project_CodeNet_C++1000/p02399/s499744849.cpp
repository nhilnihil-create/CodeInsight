#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

int main(int argc, char *argv[])
{
    int a, b;
    std::cin >> a >> b;

    double f = a/(double)b;
    int r = a%b;

    std::cout << std::fixed;
    std::cout << std::setprecision(9) << (int)f << " " << r << " "<< f << std::endl;
    return 0;
}