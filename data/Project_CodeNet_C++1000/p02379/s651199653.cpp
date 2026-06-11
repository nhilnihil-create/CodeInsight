#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    double dist= sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    std::cout << std::fixed << dist << std::endl;

    return 0;
}