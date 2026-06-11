#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<double, double> p_d;

void printP(p_d p)
{
  printf("%.6f %.6f\n",p.first, p.second);
}

void koch(int n, p_d p1, p_d p2)
{
  if(n == 0) return;
  p_d s, u, t;
  s.first = (2 * p1.first + p2.first) / 3;
  s.second = (2 * p1.second + p2.second) / 3;
  t.first = (p1.first + 2 * p2.first) / 3;
  t.second = (p1.second + 2 * p2.second) / 3;
  u.first = s.first + (t.first - s.first) * cos(60 * M_PI / 180) - (t.second - s.second) * sin(60 * M_PI / 180);
  u.second = s.second + (t.first - s.first) * sin(60 * M_PI / 180) + (t.second - s.second) * cos(60 * M_PI / 180);
  koch(n-1, p1, s);
  printP(s);
  koch(n-1, s, u);
  printP(u);
  koch(n-1, u, t);
  printP(t);
  koch(n-1, t, p2);
}

int main()
{
  p_d a(0.0,0.0);
  p_d b(100.0,0.0);
  int n;
  cin >> n;
  printP(a);
  koch(n, a, b);
  printP(b);
  return 0;
}