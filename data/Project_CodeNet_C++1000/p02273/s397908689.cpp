#include <iostream>
#include <cmath>
#include <iomanip>

const int MAX_N = 6;
const double DEGREE_60 = M_PI / 3.0;

struct Point {
  double x;
  double y;
};

void printPoint(struct Point *p) {
  std::cout.setf(std::ios_base::scientific, std::ios_base::floatfield);
  std::cout << std::fixed << std::setprecision(6) << p->x << " " << p->y << std::endl;
}

void rotatePoint(struct Point *b, struct Point *p) {
  double x = (p->x - b->x) * std::cos(DEGREE_60) - (p->y - b->y) * std::sin(DEGREE_60) + b->x;
  double y = (p->x - b->x) * std::sin(DEGREE_60) + (p->y - b->y) * std::cos(DEGREE_60) + b->y;

  p->x = x;
  p->y = y;
}

double getDividingPoint(double p1, double p2, double k, double l) {
  return (p1 * l + p2 * k) / (k + l);
}

void printKochCurve(struct Point p1, struct Point p2, int c, int n) {
  if (c > n) {
    return;
  }

  const double k = 1.0;
  const double l = 2.0;

  struct Point s = {getDividingPoint(p1.x, p2.x, k, l) , getDividingPoint(p1.y, p2.y, k, l)};
  struct Point t = {getDividingPoint(p1.x, p2.x, l, k) , getDividingPoint(p1.y, p2.y, l, k)};
  
  struct Point u = {t.x , t.y};
  rotatePoint(&s, &u);

  printKochCurve(p1, s, c + 1, n);
  printPoint(&s);

  printKochCurve(s, u, c + 1, n);  
  printPoint(&u);

  printKochCurve(u, t, c + 1, n);  
  printPoint(&t);
  
  printKochCurve(t, p2, c + 1, n);
}

int main(void) {
  int n = 0;

  std::cin >> n;

  struct Point p1 = {0.0, 0.0};
  struct Point p2 = {100.0, 0.0};  

  printPoint(&p1);
  printKochCurve(p1, p2, 1, n);
  printPoint(&p2);

  return 0;
}