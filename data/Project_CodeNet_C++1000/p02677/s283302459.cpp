#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#define pi 3.141592653589793238462643383L
using namespace std;

int main(void){
  int a,b,hour,minu;
  double angh,angm;
  cin >> a >> b >> hour >> minu;
  angh = hour *(pi/6)+minu*(pi/360);
  angm = minu*pi/30;
  double ans;
  vector<long double> xy(2);
  xy[0] = ((sin(angm)*b)-(sin(angh)*a));
  xy[1] = ((cos(angm)*b)-(cos(angh)*a));
  ans = sqrt((xy[0]*xy[0])+(xy[1]*xy[1]));
  printf("%.15f", ans);
  return 0;
}