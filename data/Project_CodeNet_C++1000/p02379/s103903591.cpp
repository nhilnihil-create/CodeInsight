#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    double x1, y1, x2, y2;

    std::cin >> x1 >> y1 >> x2 >> y2;

    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    std::cout << std::fixed << std::setprecision(30) << distance << std::endl;

    return 0;
}
