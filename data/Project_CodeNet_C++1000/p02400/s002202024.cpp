#include <iostream>
#include <cstdio>
using namespace std;
#define PI 3.141592653589

int main(void){
    double x, z;
    cin >>x;
    z=x*PI;
    printf("%.6f %.6f\n",z*x,z*2.0); 
    return 0;
}