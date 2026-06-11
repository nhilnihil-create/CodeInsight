#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

#define pi  3.141592653589793

int main(){

	int a, b;
  double theta;
  cin >> a >> b >> theta;
  theta =pi*theta/180;
 
  double S = a * b * sin(theta)/2;
 
  double c = sqrt(a*a + b*b - 2*a*b*cos(theta));
  double L = a + b + c;
  double h = S*2/a;
  printf("%.8lf \n", S);
  printf("%.8lf \n", L);
  printf("%.8lf \n", h);
return 0;
}