#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

class point_t{
public:
  //?????????????????§public???
  double x, y, rad;


  point_t(double x, double y, double rad): x(x), y(y), rad(rad)
  {
    //x = cos(rad / 360.0 * 2 * M_PI);
    //y = sin(rad / 360.0 * 2 * M_PI);
  }
  void print(){cout << fixed << setprecision(10) << x << " " << y << endl;}
};

void rec(point_t t1, point_t t2, int n){
  if(n==0)  return;
  double lx = t1.x, ly = t1.y;
  double rx = t2.x, ry = t2.y;
  double th = M_PI * 60 / 180.0;

    //s
  point_t p1((2*lx+rx)/3.0, (2*ly+ry)/3.0, t1.rad + 60);
    //t
  point_t p2((lx+rx*2)/3.0, (ly+ry*2)/3.0, t1.rad);
    //u
  point_t p3((p2.x - p1.x) * cos(th) - (p2.y - p1.y) * sin(th) + p1.x, 
    (p2.x - p1.x) * sin(th) + (p2.y - p1.y) * cos(th) + p1.y, t1.rad - 60);

  rec(t1, p1, n-1);
  p1.print();
  rec(p1, p3, n-1);
  p3.print();
  rec(p3, p2, n-1);
  p2.print();
  rec(p2, t2, n-1);
}

int main(void){
  int n;
  cin >> n;
  point_t t1(0, 0, 0);
  point_t t2(100, 0, 0);

  t1.print();
  rec(t1, t2, n);
  t2.print();
  
  return 0;
}