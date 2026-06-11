#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main() {
    double r;
    cin >> r;
    printf("%lf %lf\n", pow(r,2)*M_PI, 2*r*M_PI);
}