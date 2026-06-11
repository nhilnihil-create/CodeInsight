#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(){

  long double a,b,x;

  cin >> a >> b >> x;

  long double  t;
  if(x>=a*a*b/2)t= atan(2*(a*a*b-x)/(a*a*a))*180/3.1415926535 ;
  else t= 90.0000000-atan(2*x/(a*b*b))*180/3.1415926535;

  printf("%.12Lf",t);

}