#include<iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;
int main(){

  double a,b,c;

  cin >> a >> b >> c;
  cout << setprecision(15) << a*b*sin(c * M_PI / 180.0)/2 << endl;
  cout << setprecision(15) << (a+b+ sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c * M_PI / 180.0))) << endl;
  cout << setprecision(15) << b*sin(c * M_PI / 180.0) <<  endl;

}



