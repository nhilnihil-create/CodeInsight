#include<iostream>
#include<cmath>
#include<cstdio>

#define PI 3.14159265358979

using namespace std;

struct P {
  double x;
  double y;
};

void Plot(int n, P a, P b) {
  if (n == 0) {
    return;
  }

  double th = 60.0 * (PI / 180.0); // degree to rad

  P s, t, u;
  s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
  t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;  
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y ) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y ) * cos(th) + s.y;  

  Plot(n - 1, a, s);
  printf("%.8lf %.8lf\n", s.x, s.y);
  Plot(n - 1, s, u);
  printf("%.8lf %.8lf\n", u.x, u.y);
  Plot(n - 1, u, t);
  printf("%.8lf %.8lf\n", t.x, t.y);
  Plot(n - 1, t, b);
}
 
int main() {
  const P A = {0.0, 0.0}, B = {100.0, 0.0};
  int N;

  cin >> N;

  printf("%.8lf %.8lf\n", A.x, A.y);
  Plot(N, A, B);
  printf("%.8lf %.8lf\n", B.x, B.y);

  return 0;
}
