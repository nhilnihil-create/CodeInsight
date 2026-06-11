#include<iostream>
#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES
using namespace std;

int main(void){

  double input;
  double circle,line;

  cin >> input;

  circle = M_PI*input*input;
  line = 2*M_PI*input;

  printf("%.6lf %.6lf\n",circle,line);

  return 0;

}