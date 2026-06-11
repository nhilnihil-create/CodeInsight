#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Point {
  double x;
  double y;
  Point(double x, double y): x(x), y(y) {}
};

Point get_top(Point p1, Point p2) {
  double pi3 = M_PI / 3;
  double x = (p2.x - p1.x) * cos(pi3) - (p2.y - p1.y) * sin(pi3) + p1.x;
  double y = (p2.x - p1.x) * sin(pi3) + (p2.y - p1.y) * cos(pi3) + p1.y;

  return Point(x, y);
}

vector<Point> koch(Point start, Point end, int depth) {
  auto p1 = Point((start.x * 2 + end.x) / 3, (start.y * 2 + end.y) / 3);
  auto p2 = Point((start.x + end.x * 2) / 3, (start.y + end.y * 2) / 3);
  
  auto top = get_top(p1, p2);

  vector<Point> t;
  if (!depth) {
    t.push_back(start);
    t.push_back(end);
  }

  if (depth > 0) {
    for (auto p: koch(start, p1, depth - 1)) t.push_back(p);
    t.pop_back();
    for (auto p: koch(p1, top, depth - 1)) t.push_back(p);
    t.pop_back();
    for (auto p: koch(top, p2, depth - 1)) t.push_back(p);
    t.pop_back();
    for (auto p: koch(p2, end, depth - 1)) t.push_back(p);
  }

  return t;
}

int main() {
  int n;
  cin >> n;

  Point start(0, 0), end(100.0, 0);
  auto t = koch(start, end, n);
  
  for (auto p: t) 
    printf("%.10lf %.10lf\n", p.x, p.y);
}

