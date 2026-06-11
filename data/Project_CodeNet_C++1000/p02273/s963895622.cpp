#include<stdio.h>
#include<math.h>

struct Point { double x, y; };

void koch( int n, Point a, Point b) {
  if ( n == 0 ) return;
  Point a1, b1, ab;
  double th = M_PI * 60.0 / 180.0;
  
  a1.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  a1.y = (2.0 * a.y + 1.0 * b.y) / 3.0;

  b1.x = (1.0 * a.x + b.x * 2.0) / 3.0;
  b1.y = (1.0 * a.y + b.y * 2.0) / 3.0;
  
  ab.x = (b1.x - a1.x) * cos(th) - (b1.y - a1.y) * sin(th) + a1.x;
  ab.y = (b1.x - a1.x) * sin(th) + (b1.y - a1.y) * cos(th) + a1.y;

  koch( n - 1, a, a1);
  printf("%.8f %.8f\n", a1.x, a1.y);
  koch( n - 1, a1, ab);
  printf("%.8f %.8f\n", ab.x, ab.y);
  koch( n - 1, ab, b1);
  printf("%.8f %.8f\n", b1.x, b1.y);
  koch( n - 1, b1, b);
}

int main() {
  Point a, b;
  int n;

  scanf("%d", &n);

  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;

  printf("%.8f %.8f\n", a.x, a.y);
  koch(n, a, b);
  printf("%.8f %.8f\n", b.x, b.y);

  return 0;
}
