#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a,b,c,C,S,h,L;
    cin >> a >> b >> C;
    h = b*sin(C * M_PI / 180);
    S = 0.5 * a * h;
    L = a+b+sqrt(a*a+b*b-2*a*b*cos(M_PI /180 * C));

    cout << setprecision(10) << S << endl;
    cout << setprecision(10) << L << endl;
    cout << setprecision(10) << h << endl;
    return 0;
}