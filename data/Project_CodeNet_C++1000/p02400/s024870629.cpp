#include <iostream>
#include <cstdio>

int main()
{
    double r;
    double pi = 3.14159265358979;

    std::cin >> r;

    std::printf("%f %f\n",r * r * pi, 2 * pi * r);

    return 0;
}