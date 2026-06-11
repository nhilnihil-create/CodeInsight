#include <bits/stdc++.h>
using namespace std;
int n;
class Point{
  public:
  double x;
  double y;
  Point(){}
  Point(double _x, double _y){
    x = _x;
    y = _y;
  }
  Point operator+(const Point &p)const{
    Point res;
    res.x = x + p.x; res.y = y + p.y;
    return res;
  }
  double length(){
    return sqrt(x*x+y*y);
  }
};

void func(int i, Point l, Point r){
  if(i == n) return;
  Point s, t, u;
  Point sum = r+l;
  s = Point((l.x * 2.0 + r.x)/3.0, (2*l.y + r.y)/3.0);
  t = Point((l.x + 2*r.x)/3.0, (l.y + 2*r.y)/3.0);
  u = Point(cos(M_PI/3)*(t.x - s.x) - sin(M_PI/3)*(t.y - s.y) + s.x,
            sin(M_PI/3)*(t.x - s.x) + cos(M_PI/3)*(t.y - s.y) + s.y
           );
  func(i+1, l, s);
  printf("%.10f %.10f\n", s.x, s.y);
  func(i+1, s, u);
  printf("%.10f %.10f\n", u.x, u.y);
  func(i+1, u, t);
  printf("%.10f %.10f\n", t.x, t.y);
  func(i+1, t, r);
  return;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  Point p1(0, 0), p2(100, 0);
  printf("%.10f %.10f\n", p1.x, p1.y);
  func(0, p1, p2);
  printf("%.10f %.10f\n", p2.x, p2.y);

  return 0;
}