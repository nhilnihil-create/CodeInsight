#include <cstdio>

using namespace std;

static const double PI=3.141592653589793;

int main() {
    double r;
    scanf("%lf", &r);

    printf("%.12f %.12f\n", PI*r*r, 2*PI*r);
    return 0;
}