#include <iostream>
#include <iomanip>

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    int d = a / b;
    int r = a % b;
    double f = static_cast<double>(a) / static_cast<double>(b);
    std::cout << d << " " << r << " " << std::fixed << std::setprecision(5) << f << std::endl;
    return 0;
}