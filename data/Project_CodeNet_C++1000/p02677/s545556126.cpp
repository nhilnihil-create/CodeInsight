#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    double th = double(h*60+m)/720 * 2*M_PI;
    double tm = double(m)/60 * 2*M_PI;
    double ans = sqrt(a*a + b*b - 2*a*b*cos(th - tm));
    printf("%.10f\n", ans);

    return 0;
}