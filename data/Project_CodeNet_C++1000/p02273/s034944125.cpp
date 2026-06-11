#include <stdio.h>
#include <math.h>

double COS60 = cos(M_PI / 3.0), SIN60 = sin(M_PI / 3.0);

void print(double p[2]) {
  printf("%f %f\n", p[0], p[1]);
}

void add(double ret[2], double p1[2], double p2[2]) {
  ret[0] = p1[0] + p2[0];
  ret[1] = p1[1] + p2[1];
}

void subtract(double ret[2], double p1[2], double p2[2]) {
  ret[0] = p1[0] - p2[0];
  ret[1] = p1[1] - p2[1];
}

void multiply(double ret[2], double p[2], double a) {
  ret[0] = p[0] * a;
  ret[1] = p[1] * a;
}

void devide(double ret[2], double p[2], double a) {
  ret[0] = p[0] / a;
  ret[1] = p[1] / a;
}

double norm(double x[2]) {
  return sqrt(x[0] * x[0] + x[1] * x[1]);
}

void rot60(double ret[2], double x[2]) {
  double tmp[2] = {x[0], x[1]};
  ret[0] = COS60 * tmp[0] - SIN60 * tmp[1];
  ret[1] = SIN60 * tmp[0] + COS60 * tmp[1];
}

void coch(int n, double p1[2], double p2[2]) {
  if(n == 0) {
    return;
  }
  double s[2], t[2], u[2], d[2];

  // d = ( p2 - p1 ) / 3
  subtract(d, p2, p1);
  devide(d, d, 3.0);

  // calc s
  add(s, d, p1);
  // calc u
  multiply(u, d, 2);
  add(u, u, p1);
  // calc t
  rot60(t, d);
  add(t, t, s);

  coch(n - 1, p1, s);
  print(s);
  coch(n - 1, s, t);
  print(t);
  coch(n - 1, t, u);
  print(u);
  coch(n - 1, u, p2);
}

int main(void) {
  int n;
  scanf("%d", &n);

  double p1[2] = {0.0, 0.0};
  double p2[2] = {100.0, 0.0};
  print(p1);
  coch(n, p1, p2);
  print(p2);
  return 0;
}