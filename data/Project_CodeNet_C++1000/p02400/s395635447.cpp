#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    double r,S,L,PI;
    PI = M_PI;
    cin >> r;

    S = r*r*PI;
    L = 2*r*PI;

    printf("%f %f\n",S,L );
}