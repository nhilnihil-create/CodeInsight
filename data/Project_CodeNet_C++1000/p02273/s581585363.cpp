#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int inf = 1000000000;
int koch(double lx, double ly, double rx, double ry, int n){
  if( n == 0 ){
    printf("%.10lf %.10lf\n", lx, ly);
    return 0;
  }
  double x1 = (2*lx+rx)/3;
  double y1 = (2*ly+ry)/3;

  double x3 = (lx+2*rx)/3;
  double y3 = (ly+2*ry)/3;

  double d60 = 60* M_PI / 180.0;

  double x2 = cos(d60)*(x3-x1) - sin(d60)*(y3-y1) + x1;
  double y2 = sin(d60)*(x3-x1) + cos(d60)*(y3-y1) + y1;

  koch(lx, ly, x1, y1, n-1);
  koch(x1, y1, x2, y2, n-1);
  koch(x2, y2, x3, y3, n-1);
  koch(x3, y3, rx, ry, n-1);

  return 0;
}

int main(void) {
  int n;
  cin >> n;
  koch(0.0, 0.0, 100.0, 0.0, n);
  printf("%.10lf %.10lf\n", 100.0, 0.0);
  return 0;
}

// EOF