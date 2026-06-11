#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b, h, m; cin >> a >> b >> h >> m;
    double degA, degB, deg;
    degA = 2 * M_PI * ((double)h / 12 + (double)m / 720);
    degB = 2 * M_PI * (double)m / 60;
    deg = abs(degA - degB);
    cout << fixed << setprecision(11) << sqrt((double)(a * a + b * b - 2 * a * b * cos(deg))) << endl;
    return 0;
}