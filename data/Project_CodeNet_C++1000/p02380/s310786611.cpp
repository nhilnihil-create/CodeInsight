#include <cstdio>
#include <cmath>

int main() {
    int a, b, C;
    double S, L, h, c;
    double x;
    double PI = acos(-1);
    scanf("%d %d %d", &a, &b, &C);
    x = C * PI / 180;
    h = b * sin(x);
    S = a * h / 2;
    c = sqrt(a*a + b*b - 2*a*b*cos(x));
    L = a + b + c;
    printf("%f\n%f\n%f\n", S, L, h);
    return 0;
}
