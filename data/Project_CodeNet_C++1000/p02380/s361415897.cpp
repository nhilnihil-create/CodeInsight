#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.141592653589793238
using namespace std;
int main()
{
  double a,b;
  int c;
  cin>>a>>b>>c;
  double s;
  s=a*b*sin(c*PI/180)/2;
  cout<<fixed<<s<<endl;
  cout<<a+b+sqrt(a*a+b*b-2*a*b*cos(c*PI/180))<<endl;
  cout<<2*s/a<<endl;
}