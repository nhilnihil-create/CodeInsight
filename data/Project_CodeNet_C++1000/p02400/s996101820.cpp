#include <iostream>
#include <cstdio>

constexpr auto pi = 3.14159265358979323846264338;

auto main () -> int
{
    double r;
    std::cin >> r;
    std::printf ("%.5f %.5f\n" , r*r*pi, 2*pi*r);
}