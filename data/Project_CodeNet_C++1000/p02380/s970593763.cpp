#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iomanip>

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main(){

  double a,b,c;
  double x;
  double L,S,h;

  cin >>a >>b >>c;

  x=a*a+b*b-2*a*b*cos(c*M_PI/180);

  L=sqrt(x)+a+b;
  h=b*sin(c*M_PI/180);
  S=a*h/2;

  cout <<fixed <<setprecision(8) <<S <<endl <<fixed <<setprecision(8) <<L <<endl <<fixed <<setprecision(8) <<h <<endl;

  return 0;
}