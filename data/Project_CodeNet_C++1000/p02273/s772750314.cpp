#include<cstdio>
#include<cmath>
using namespace std;

#define pi 3.141592653589793

void koch(double x1, double y1, double x2, double y2, int n) {
    if (n == 0) {
        printf("%.8f %.8f\n", x1, y1);
    }
    else {
        double sx, sy, tx, ty, ux, uy;
        sx = x1 + (x2 - x1) / 3;
        sy = y1 + (y2 - y1) / 3;
        tx = x2 - (x2 - x1) / 3;
        ty = y2 - (y2 - y1) / 3;
        ux = (tx - sx)*cos(pi / 3) - (ty - sy)*sin(pi / 3) + sx;
        uy = (tx - sx)*sin(pi / 3) + (ty - sy)*cos(pi / 3) + sy;
        koch(x1, y1, sx, sy, n-1);
        koch(sx, sy, ux, uy, n-1);
        koch(ux, uy, tx, ty, n-1);
        koch(tx, ty, x2, y2, n-1);
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    koch(0.0, 0.0, 100.0, 0.0, n);
    printf("100.00000000 0.00000000\n");
    return 0;
}
