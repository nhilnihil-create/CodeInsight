#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double theta = (60*h - 11*m) * M_PI / 360, c;
    c = sqrt(a*a + b*b - 2*a*b* cos(theta));
    cout << fixed << setprecision(9) << c << endl;
}