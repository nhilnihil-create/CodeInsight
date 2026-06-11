#include <iostream>
#include <cmath>

constexpr double PI = 3.14159265;

int main()
{
    int side1, side2, deg;
    std::cin >> side1 >> side2 >> deg;

    double rad = deg * PI / 180;

    double area = side1 * side2 * sin(rad) / 2;
    double side3 = sqrt(pow(side1, 2) + pow(side2, 2)
                        - 2 * side1 * side2 * cos(rad));
    double round = side1 + side2 + side3;
    double height = side2 * sin(rad);

    std::cout << std::fixed << area << " "
              << round << " "
              << height << std::endl;

    return 0;
}