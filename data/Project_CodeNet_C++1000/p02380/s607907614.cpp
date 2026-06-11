#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)

int main() {
    int a, b, ang_c;
    cin >> a >> b >> ang_c;
    
    double deg_c = PI * ang_c / 180.0;
    double s = a * b * sin(deg_c) / 2.0;
    double l = a + b + sqrt(a * a + b * b - 2 * a * b * cos(deg_c));
    double h = b * sin(deg_c);

    printf("%lf\n%lf\n%lf\n", s, l, h);
}