#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){

  double a, b, c;
  double angle;
  double sin1;
  double cos1;
  double s, l ,h;

  cin>>a>>b>>angle;
  angle = angle*M_PI/180.0;
  sin1 = sin(angle);
  cos1 = cos(angle);

  s = 0.5 * a * b * sin1;
  c = a*a + b*b -2.0*a*b*cos1;
  c = sqrt(c);
  l = a + b + c;
  h = 2.0*s/a;

  // cout<<sin1<<" "<<cos1<<endl;
  printf("%.16lf\n%.15lf\n%.15lf\n", s, l ,h);

}