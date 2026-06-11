#include <algorithm>
#include <iostream>
#include <cstdio>

int main()
{
    double r = 0;
    std::cin >> r;
    printf("%.7f %.7f\n", 3.14159265358979323846 * r * r, 3.14159265358979323846 * 2 * r);
    return 0;
}
