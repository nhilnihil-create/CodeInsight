#include <iostream>
#include <cstdio>

using namespace std;

#define PI 3.14159265359

int main(void)
{
    double r;
    cin >> r;

    printf("%f %f\n", r * r * PI, 2 * r * PI);
    return 0;
}