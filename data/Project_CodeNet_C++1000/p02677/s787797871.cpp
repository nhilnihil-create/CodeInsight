#include<iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
  int a,b,h,m;
  cin >> a >> b >> h >> m;

  long double rad = (m*6.0 - (h*30.0 + m*0.5)) * M_PI / 180.0;
  long double ans;
  ans = sqrt(a*a + b*b - 2*a*b*cos(rad));
  cout << fixed << setprecision(20) << ans << endl;
}