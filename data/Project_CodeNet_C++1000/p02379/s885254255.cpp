#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


int main(){


  double x[2],y[2];
  cin >> x[0] >> y[0] >> x[1] >> y[1];

  printf("%.10f\n",sqrt( (x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1]) ));


}