#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(void){
    double r;
    cin >> r;
    
    double P, S;
    P = 2 * M_PI * r;
    S = pow(r,2) * M_PI;
    
    printf("%.6lf %.6lf\n", S, P);
}