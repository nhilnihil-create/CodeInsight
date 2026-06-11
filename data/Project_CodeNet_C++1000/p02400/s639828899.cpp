#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main(){
    double r,s,l,pi;
    pi = M_PI;
    cin >> r;
    s = r * r * pi;
    l = r * 2 * pi;
    printf("%.6f %.6f",s,l);
    return 0;
}
