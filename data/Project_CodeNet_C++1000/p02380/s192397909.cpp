#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;
int main(){
    double a, b, c; cin >> a >> b >> c;
    double s, l, h;
    s = a * b * sin(c / 180.0 * pi) / 2;
    l = a + b + sqrt(a * a + b * b  - 2 * a * b * cos(c / 180.0 * pi));
    h = s * 2 / a;
    printf("%.10f\n", s);
    printf("%.10f\n", l);
    printf("%.10f\n", h);

}
