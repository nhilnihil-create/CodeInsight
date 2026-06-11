#include <cstdio>
#include <cmath>

constexpr double sqrt3_2 = sqrt(3) * 0.5;

void koch(int n, double p1x, double p1y, double p2x, double p2y){
  if(n > 0){
    double sx = (p1x * 2 + p2x) / 3;
    double sy = (p1y * 2 + p2y) / 3;
    double tx = (p1x + p2x * 2) / 3;
    double ty = (p1y + p2y * 2) / 3;
    double ux = sx + (tx - sx) * 0.5 - (ty - sy) * sqrt3_2;
    double uy = sy + (tx - sx) * sqrt3_2 + (ty - sy) * 0.5;
    koch(n - 1, p1x, p1y, sx, sy);
    printf("%lf %lf\n", sx, sy);
    koch(n - 1, sx, sy, ux, uy);
    printf("%lf %lf\n", ux, uy);
    koch(n - 1, ux, uy, tx, ty);
    printf("%lf %lf\n", tx, ty);
    koch(n - 1, tx, ty, p2x, p2y);
  }
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%lf %lf\n", 0.0, 0.0);
  koch(n, 0.0, 0.0, 100.0, 0.0);
  printf("%lf %lf\n", 100.0, 0.0);
}