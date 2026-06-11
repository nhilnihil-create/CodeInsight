#define pi 3.14159265358979323846

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    long double a, b, h, m;
    cin >> a >> b >> h >> m;
    //calculating deg
    long double hdeg = h * 30;
    long double mdeg = m * 6;
    hdeg += mdeg / 12;
    long double deg = abs(hdeg - mdeg);
    //apply law of cosines
    long double cosdeg = cos(deg * pi / 180);
    long double asqr = a * a;
    long double bsqr = b * b;
    long double c = sqrt(asqr + bsqr - 2 * a * b * cosdeg);
    cout << fixed << showpoint;
    cout << setprecision(20);
    cout << c << endl;
    return 0;


}
