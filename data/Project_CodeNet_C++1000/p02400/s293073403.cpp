#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
    double pi = 3.1415926535897932384626433832795028841971;
    double r;
    
    cin >> r;
    printf("%7lf %7lf\n",r*r*pi,r*2*pi);
    return 0;
}