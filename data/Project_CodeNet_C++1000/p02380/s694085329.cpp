#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, C;
    double area, length, height, opposite_side;
    cin >> a >> b >> C;
    C = C / 180 * M_PI;
    area = a * b * sin(C) / 2.0;
    opposite_side = sqrt(a * a + b * b - 2 * a * b * cos(C));
    length = a + b + opposite_side;
    height = area / a * 2.0;

    printf("%10.8f\n", area);
    printf("%10.8f\n", length);
    printf("%10.8f\n", height);

    return 0;
}
