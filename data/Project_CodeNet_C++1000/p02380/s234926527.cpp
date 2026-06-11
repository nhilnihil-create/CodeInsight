#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
    double a,b,C;
    cin >> a >> b >> C;
    double theta = M_PI*C/180;

    double S = 0.5*a*b*sin(theta);
    double c = a*a+b*b-2*a*b*cos(theta);
    double L = a+b+sqrt(c);
    double h = S/a*2;

    cout << fixed << S << endl;
    cout << fixed << L << endl;
    cout << fixed << h << endl;
    return 0;
}