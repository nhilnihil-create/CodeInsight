#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int h, m, a, b;
const double PI = 3.141592653589793238462643383;


int main() {
    cin >> a >> b >> h >> m;
    double hourAngle = (double)(30*h)+(0.5*m);
    double minuteAngle = (double)(6*m);
    double angle = ((hourAngle > minuteAngle) ? hourAngle-minuteAngle : minuteAngle-hourAngle);
    angle = min(angle, 360-angle);
    double ans = sqrt((double)(a*a)+(double)(b*b) - (double)(2*a*b*cos(angle*PI/180)));
    cout << fixed << setprecision(10) << ans;
}
