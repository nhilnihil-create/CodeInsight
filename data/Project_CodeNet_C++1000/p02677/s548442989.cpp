#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define pi 3.14159265358979323846
using namespace std;
int main(){
  long double a,b,h,m;
  cin >> a >> b >> h >> m;
  cout << fixed << setprecision(20) << sqrt(a*a+b*b-2*a*b*cos(min({abs(30*h-5.5*m),\
abs(5.5*m-30*h),abs(360-30*h+5.5*m),abs(360-5.5*m+30*h)})*pi/180)) << "\n";
  return 0;
}
