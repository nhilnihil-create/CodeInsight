#include<iostream>
#include<cstdio>
using namespace std;

int main(){
 double r,a,b,pi = 3.141592653589;

 cin >> r;

 a = pi * r * r;
 b = 2 * pi *r;

 printf("%f %f\n" ,a,b);

 return 0;
}