#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    double a, b, x, p = 3.1415926535;
    cin >> a >> b >> x;
    double v = a * a * b, TAN;
    if(x <= v / 2) TAN = a * b * b / (2 * x);
    else TAN = 2 * (v - x) / (a * a * a);
    cout << setprecision(12) << atan(TAN) * 180 / p << endl;
}