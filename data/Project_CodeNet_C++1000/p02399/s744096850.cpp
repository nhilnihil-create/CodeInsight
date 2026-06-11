#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    double a, b;
    int d;
    double r, f;
    cin >>a >>b;

    d = a/b;
    r = fmod(a,b);
    f = a/b;

    printf("%d %.0f %f\n",d,r,f );
 
}