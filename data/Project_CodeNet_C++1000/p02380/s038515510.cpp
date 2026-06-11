#include <cstdio>
#include <cmath>
using namespace std;

int main(void){
    double a, b, c, s, l, h;
    scanf("%lf %lf %lf", &a, &b, &c);
    c = c * acos(-1) / 180;
    h = b * sin(c);
    s = a * h / 2;
    l = a + b + sqrt(pow(a - b * cos(c), 2) + pow(h, 2));
    printf("%lf\n", s);
    printf("%lf\n", l);
    printf("%lf\n", h);
    return 0;
}
