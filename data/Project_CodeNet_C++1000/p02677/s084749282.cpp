#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    double pi = 3.141592653589793;
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double Ax = a * std::cos(2*pi*(60*h+m)/720);
    double Ay = a * std::sin(2*pi*(60*h+m)/720);
    double Bx = b * std::cos(2*pi*m/60);
    double By = b * std::sin(2*pi*m/60);

    double ans = sqrt(std::pow(Ax-Bx, 2) + std::pow(Ay-By, 2));
    printf("%.10f\n", ans);
    return 0;
}