#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
using namespace std;
int main() {
double r;
cin >> r;
printf("%0.8f %0.8f", pow((double)r, (double)2) * M_PI , (double)r * (double)2 * M_PI);

}