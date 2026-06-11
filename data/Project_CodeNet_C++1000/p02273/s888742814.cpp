#include <iostream>
#include <cmath>
using namespace std;
 
struct Point {
  double x, y;
};
 
void printPoint(Point p) {
  cout << fixed << p.x << " " << p.y << endl;
}
 
void KochCurve(Point p1, Point p2, int rec, int n) {
  if (rec < n) {
    Point s, t, u;
    double deg = 60.0*(M_PI/180.0);
    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    u.x = s.x + (t.x - s.x) * cos(deg) - (t.y - s.y) * sin(deg);
    u.y = s.y + (t.x - s.x) * sin(deg) + (t.y - s.y) * cos(deg);
    rec++;
    KochCurve(p1, s, rec, n);
    printPoint(s);
    KochCurve(s, u, rec, n);
    printPoint(u);
    KochCurve(u, t, rec, n);
    printPoint(t);
    KochCurve(t, p2, rec, n);
  }
}
 
int main () {
  int n;
  Point p1, p2;
  p1.x = 0.0;
  p1.y = 0.0;
  p2.x = 100.0;
  p2.y = 0.0;
 
  cin >> n;
  printPoint(p1);
  KochCurve(p1, p2, 0, n);
  printPoint(p2);
  return 0;
}