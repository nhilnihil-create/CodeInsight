#include <iostream>
#include <cmath>
#include <cstdio>
             
int main() { 
    double r, l, area = 0.0;
             
    std::cin >> r;
    l = 2 * M_PI * r;
    area = M_PI * r * r;
             
    printf("%f %f\n", area, l);
    return 0;
}