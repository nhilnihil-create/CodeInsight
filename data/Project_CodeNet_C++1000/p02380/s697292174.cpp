#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <stdio.h>
#define MAXSIZE 101
#define PI 3.141592653589
using namespace std;
int main(){
  double a,b,c;
  std::cin >> a>>b>>c;
  printf("%.8f\n",a*b*sin(c*PI/180)/2);
  printf("%.8f\n",a+b+sqrt(a*a+b*b-2*a*b*cos(c*PI/180)));
  printf("%.8f\n",a*b*sin(c*PI/180)/a);

}