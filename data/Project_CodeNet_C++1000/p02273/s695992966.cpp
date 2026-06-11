#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int N;
double cos60 = 1.0 / 2.0;
double sin60 = sqrt(3) / 2.0;

class Point
{
  public:
    Point(double _x, double _y) : x(_x), y(_y) {}

    double x;
    double y; 

    void print()
    { printf("%08f %08f\n", this->x, this->y); }
};

void kock(int n, Point &p1, Point &p2)
{
  if(n == 0)
    return;

  const double dx = p2.x - p1.x, dy = p2.y - p1.y;

  Point s(p1.x + 1.0 / 3.0 * dx, p1.y + 1.0 / 3.0 * dy);
  Point t(p1.x + 2.0 / 3.0 * dx, p1.y + 2.0 / 3.0 * dy);
  Point u(1.0 / 3.0 * (cos60 * dx - sin60 * dy) + s.x, 
          1.0 / 3.0 * (sin60 * dx + cos60 * dy) + s.y);

  kock(n-1, p1, s);
  s.print();
  kock(n-1, s, u);
  u.print();
  kock(n-1, u, t);
  t.print();
  kock(n-1, t, p2);

}

int main()
{
  cin >> N;
 
  Point p1(0.0, 0.0), p2(100.0, 0.0);

  p1.print();
  kock(N, p1, p2);
  p2.print();

  return 0;
}

