#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;

    double S = 0.5 * a * b * sin(c * M_PI/180);

    double L = a + b + sqrt(a*a + b*b - 2 * a * b* cos(c * M_PI/180));

    double h = b * sin(c*M_PI/180);

    std::cout << std::fixed << std::setprecision(20) << S << std::endl;
    std::cout << L << std::endl;
    std::cout << h << std::endl;

    return 0;
}
