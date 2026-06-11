#include <iostream>
#include <cmath>

int main()
{
    int a, b;

    std::cin >> a >> b;

    std::printf("%d\n", a / b);
    std::printf("%d\n", a % b);

    double aa = static_cast<double>(a);
    double bb = static_cast<double>(b);

    std::printf("%lf\n", aa / bb);
    return 0;


}