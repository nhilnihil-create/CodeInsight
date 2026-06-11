#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <cstdio>

int main(){
double r;

std::cin >> r;

std::printf("%.5f %.5f", r*r*M_PI, 2*r*M_PI);
}