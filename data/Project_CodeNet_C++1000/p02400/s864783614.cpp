#include <iostream>
#include <iomanip>

constexpr double PI = 3.141592653589;

int main(void)
{
    double r;
    std::cin >> r;

    double area = PI * r * r;
    double round = 2 * PI * r;
    std::cout << std::fixed << std::setprecision(6)
              << area << " " << round << std::endl;

    return 0;
}