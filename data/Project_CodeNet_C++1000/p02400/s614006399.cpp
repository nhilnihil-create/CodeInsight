#include <cmath>
#include <cstdio>

int main() {
    double r;
    scanf("%lf", &r);
    printf("%.5f %.5f\n", pow(r, 2) * M_PI, 2 * r * M_PI);
    return 0;
}
