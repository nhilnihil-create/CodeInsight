#include <iostream>
#include <iomanip>

static const double PI = 3.14159265359;

int main(void)
{
    double r;
    std::cin >> r;
    double area = r * r * PI;
    double circumference = 2 * r * PI;
    std::cout << std::fixed << std::setprecision(6) << area << " " << circumference << std::endl;
    return 0;
}