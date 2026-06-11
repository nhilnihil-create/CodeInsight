#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main () {

 double rad, are, len;

 cin >> rad;

 are = M_PI * rad * rad;
 len = M_PI * 2 * rad;
 
 printf("%lf %lf\n", are, len);

 return 0;
}