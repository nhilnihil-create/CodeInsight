#include <cstdio>
#include <cmath>
#define loop_input(fmt,...) while(~scanf(fmt,__VA_ARGS__))
#define PI 3.14159265359

int main() {
    double r;
    loop_input("%lf", &r) {
        printf("%lf %lf\n", PI * r * r, 2 * PI * r);
    }
    return 0;
}
