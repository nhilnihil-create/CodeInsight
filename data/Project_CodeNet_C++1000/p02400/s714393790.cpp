#include<iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
using namespace std;

int main(){
    double a;
    cin >> a;
    printf("%.6f %.6f\n",a*a*M_PI,2*M_PI*a);
    return 0;
}
