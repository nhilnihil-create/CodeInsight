#include <iostream>
#include <stdio.h>

int main(){
    double const PI = 3.141592653589;

    double r = 0.0f;
    std::cin >> r;

    double size = r * r * PI;
    double cir  = (r + r) * PI;

    printf( "%f %f\n", size, cir );

    return 0;
}