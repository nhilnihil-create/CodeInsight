#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define EPS 1e-4
#define PI 3.14159265358979

struct Point{double x, y;};

void koch(int d, Point p1, Point p2){
  if(d == 0) return;
  Point s, u, t;
  double th = PI * 60.0 / 180.0;

  s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
  s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
  t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
  t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
  
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

  koch(d-1, p1, s);
  cout << fixed << setprecision(8) << s.x << " " << s.y << endl;
  koch(d-1, s, u);
  cout << fixed << setprecision(8) << u.x << " " << u.y << endl;
  koch(d-1, u, t);
  cout << fixed << setprecision(8) << t.x << " " << t.y << endl;
  koch(d-1, t, p2);
}

int main(void){
  int n;
  cin >> n;
  
  Point p1, p2;
  p1.x = 0.0; p1.y = 0.0;
  p2.x = 100.0; p2.y = 0.0;

  cout << fixed << setprecision(8) << p1.x << " " << p1.y << endl;
  koch(n, p1, p2);
  cout << fixed << setprecision(8) << p2.x << " " << p2.y << endl;
  
  return 0;
}