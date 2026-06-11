#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double radius, area, circumference;

    cin >> radius;

    area = M_PI * radius * radius;
    circumference = 2 * M_PI * radius;

    printf("%lf %lf\n", area, circumference);

    return 0;
}