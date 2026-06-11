#include <cstdio>
#include <cmath>

int main() {
    int a, b, C;
    scanf("%d %d %d", &a, &b, &C);
    
    double PI = acos(-1);
    double radC = C * PI / 180;
    double S = a * b * sin(radC) / 2;
    double L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(radC));
    double h = 2 * S / a;
    printf("%.5lf\n%.5lf\n%.5lf\n", S, L, h);
}
