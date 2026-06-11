#include<iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    double r,s,c;
    
    cin >> r;
    c = 2 * r * M_PI;
    s = r * r * M_PI;
  
    printf("%f %f\n", s,c);

    return 0;
}