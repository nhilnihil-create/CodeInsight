#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
double r;
cin >> r;

double S, L;
double pi = 3.141592653589;
S = pi * r * r;
L = 2 * pi * r;

printf("%f %f\n", S, L);
}
