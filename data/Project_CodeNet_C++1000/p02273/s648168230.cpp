#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

struct Point {
  double x;
  double y;
};

void kock(int n, Point p1, Point p2) {
  if (n == 0) return;
  Point s, t, u;
  double r = 60.0 * M_PI / 180.0;
  s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
  s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
  t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
  t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
  u.x = (t.x - s.x) * cos(r) - (t.y - s.y) * sin(r) + s.x;
  u.y = (t.x - s.x) * sin(r) + (t.y - s.y) * cos(r) + s.y;
  kock(n -1, p1, s);
  printf("%.8f %.8f\n", s.x, s.y);
  kock(n -1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  kock(n -1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  kock(n -1, t, p2);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  Point p1, p2;
  p1.x = 0.0;
  p1.y = 0.0;
  p2.x = 100.0;
  p2.y = 0.0;
  printf("%.8f %.8f\n", p1.x, p1.y);
  kock(n, p1, p2);
  printf("%.8f %.8f\n", p2.x, p2.y);

  return 0;
}