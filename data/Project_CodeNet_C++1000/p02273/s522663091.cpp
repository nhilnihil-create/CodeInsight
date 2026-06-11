#include<iostream>
#include<math.h>
#include<stdio.h>
double PI = M_PI * 60 / 180;

using namespace std;

void solve(int deep, pair<double, double> begin, pair<double, double> end) {
  if(deep == 0) {
    return;
  }
  pair<double, double> s = make_pair((2 * begin.first + end.first) / 3, (2 * begin.second + end.second) / 3);
  pair<double, double> t = make_pair((begin.first + 2 * end.first) / 3, (begin.second + 2 * end.second) / 3);
  double uForx = (t.first - s.first) * cos(PI) - (t.second - s.second) * sin(PI) + s.first;
  double uFory = (t.first - s.first) * sin(PI) + (t.second - s.second) * cos(PI) + s.second;
  pair<double, double> u = make_pair(uForx, uFory);
  solve(deep - 1, begin, s);
  printf("%.8f %.8f\n", s.first, s.second);
  solve(deep - 1, s, u);
  
  printf("%.8f %.8f\n", u.first, u.second);
  solve(deep - 1, u, t);
  printf("%.8f %.8f\n", t.first, t.second);

  solve(deep - 1, t, end);
}


int main(void) {
  int n;

  cin >> n;
  pair<double, double> begin = make_pair(0, 0);
  printf("%.8f %.8f\n", begin.first, begin.second);
  pair<double, double> end = make_pair(100, 0);
  solve(n, begin, end);
  printf("%.8f %.8f\n", end.first, end.second);
  return 0;
}