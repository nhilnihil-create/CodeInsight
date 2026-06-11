#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    double dx=x2-x1, dy=y2-y1;

    printf("%.12f\n", sqrt(dx*dx+dy*dy));
    return 0;
}