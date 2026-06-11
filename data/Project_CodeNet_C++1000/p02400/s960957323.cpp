#include<iostream>
#include<stdio.h>
using namespace std;


int main(){
        double r, pi = 3.14159265359;
        cin >> r;
        double l = 2*pi*r;
        double s = pi*r*r;

        printf("%f %f\n", s, l);

        return 0;
}