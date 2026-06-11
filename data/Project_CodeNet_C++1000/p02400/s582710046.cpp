#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    double r,s,l,PI;
    PI = acos(-1);
    cin >> r;
    s = r*r*PI;
    l = 2*r*PI;
    printf("%f %f\n", s,l);
    return 0;
}