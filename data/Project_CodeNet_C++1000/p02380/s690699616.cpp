#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    c = c * (M_PI/180);
    double S = ((a*b)*sin(c))/2;
    double L = a + b + sqrt((a*a+b*b)-(2*a*b*cos(c)));
    double h = b * sin(c);
    cout << fixed << setprecision(6) << S << endl;
    cout << fixed << setprecision(6) << L << endl;
    cout << fixed << setprecision(6) << h << endl;
    return 0;
}

