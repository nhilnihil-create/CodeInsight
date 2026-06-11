#include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main() {
  int a,b,c;
  double s,l,h,pi=3.14159265358979;
  cin>>a>>b>>c;
  s=a*b*sin(c*pi/180)*1/2;
  l=sqrt(a*a+b*b-2*a*b*cos(c*pi/180))+a+b;
  h=b*sin(c*pi/180);
  cout<<fixed<<setprecision(6)<<s<<endl<<l<<endl<<h<<endl;
  return 0;
}