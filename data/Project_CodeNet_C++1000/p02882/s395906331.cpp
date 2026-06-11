#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const double pi = 3.1415926535;

int main() {
    long double a, b, x;
    cin >> a >> b >> x;

    long double V = a * a * b;
    if (x <= V / 2) {
        cout << fixed << setprecision(8) << atan(a * b * b / 2 / x) * 180 / pi << endl;
    } else {
        cout << fixed << setprecision(8) << atan(2 / (a * a * a) * (V - x)) * 180 / pi << endl;
    }
}

