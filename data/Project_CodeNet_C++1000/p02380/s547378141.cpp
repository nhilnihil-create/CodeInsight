#define _USE_MATH_DEFINES

#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>

using namespace std;

int main()
{
    int a,b,C;
    cin>>a>>b>>C;

    double S,L,h;

    h = b * sin(M_PI* C /180);
    S = a*h/2;
    L = a + b + pow(pow(a,2) + pow(b,2) - 2*a*b*cos(M_PI*C/180),0.5);

    printf("%.4f\n", S);
    printf("%.4f\n", L);
    printf("%.4f\n", h);
    return 0;
}