#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>

using namespace std;

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

int main(){

  double a,b,c;

  scanf("%lf %lf %lf",&a,&b,&c);

  printf("%.9lf\n",a*b*sin(c*M_PI/180)/2);
  printf("%.9lf\n",sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c*M_PI/180))+a+b);
  printf("%.9lf\n",sin(c*M_PI/180)*b);

}
