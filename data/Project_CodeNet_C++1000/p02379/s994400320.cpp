#include<iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;
int main(){

  double x1,y1,x2,y2;

  cin >> x1>>y1>>x2>>y2;

  cout << setprecision(15) << sqrt(pow(x2-x1,2)+pow(y2-y1,2)) << endl;

}



