#include<stdio.h>
#include<math.h>

void koch(int depth, int n, double p1x, double p1y, double p2x, double p2y) {
  if (depth != n) {
    double sx, sy, ux, uy, tx, ty;
    sx = (p1x*2+p2x)/3;
    sy = (p1y*2+p2y)/3;
    tx = (p1x+p2x*2)/3;
    ty = (p1y+p2y*2)/3;
    ux = sx+(tx-sx)*cos(60 * M_PI / 180.0)-(ty-sy)*sin(60 * M_PI / 180.0);
    uy = sy+(tx-sx)*sin(60 * M_PI / 180.0)+(ty-sy)*cos(60 * M_PI / 180.0);
    koch(depth+1, n, p1x, p1y, sx, sy);
    printf("%f %f\n", sx, sy);
    koch(depth+1, n, sx, sy, ux, uy);
    printf("%f %f\n", ux, uy);
    koch(depth+1, n, ux, uy, tx, ty);
    printf("%f %f\n", tx, ty);
    koch(depth+1, n, tx, ty, p2x, p2y);
  }
}

int main() {
	int n;
  scanf("%d", &n);
  printf("0.00000000 0.00000000\n");
  koch(0, n, 0.00000000, 0.00000000, 100.00000000, 0.00000000);
  printf("100.00000000 0.00000000\n");

  return 0;
}

