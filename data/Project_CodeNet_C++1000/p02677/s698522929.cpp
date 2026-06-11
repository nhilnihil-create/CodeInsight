#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    long double pi = acos(-1);
    long double hangle = (2*pi/720)*(h*60 + m);
    long double mangle = (2*pi/60)*m;
    long double dif = abs(hangle - mangle);
    if (dif == pi) {
        cout << a + b;
        return 0;
    }
    if (dif > pi) {
        dif = 2*pi - dif;
    }
    long double c = sqrt(pow(a,2) + pow(b,2) - 2*a*b*cos(dif));
    cout << setprecision(40) << c;
}
