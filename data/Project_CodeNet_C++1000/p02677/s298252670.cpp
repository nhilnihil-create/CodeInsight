#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// -- prop methods ----------
template<class T> inline T sq(T x){return x*x;}
template<class T> inline int sgn(T x){return x?(x>0?1:-1):0;}
// -- geometry -------------
double rad2deg(double radian){return radian/3.141592653589*180;}
double deg2rad(double degree){return degree/180*3.141592653589;}
double normalizeAngle(double a/*degree*/){ // return val is in [0...180] deg.
  while (a<0||a>360){ a += a<0? 360: -360; }  
  return a>180? 360-a: a;
}

int main(void){
  int a,b,h,m;
  double th, ph, angle;
  double ans;
  
  cin >> a >> b >> h >> m;
  th = 360.0*h/12 + 30.0*m/60;
  ph = 360.0*m/60;
  angle = deg2rad(normalizeAngle(th-ph));
  ans = sqrt(sq(a)+sq(b)-2*a*b*cos(angle));
  cout << setprecision(12);
  cout << ans << endl;
  
  return 0;
}