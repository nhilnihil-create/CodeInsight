#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double a,b,c=0,s=0,l=0,h=0;
  int cd;
  cin >> a >> b >> cd;
  if(cd==90){
    s=(a*b)/2;
    c=sqrt( a*a+b*b );
    l=a+b+c;
    h=b;
  }else{
    double rad= (double) (cd*3.141592653589)/180;
    s=( a*b*sin(rad) )/2;
    c=sqrt( a*a+b*b-2*a*b*cos(rad) );
    l=a+b+c;
    h=(2*s)/a;
  }
  cout.precision(12);
  cout << showpoint << s << endl << l << endl << h << endl;
  
  return 0;
}