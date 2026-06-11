#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);

    double a,b,c;
    double s,l,h;

    cin >> a >> b >> c;

    s = (1.0 / 2) * a * b * sin(PI/180*c);
    l = sqrt(pow(a,2) + pow(b,2) - 2.0 *a *b *cos(PI/180*c)) + a + b;
    h = b * sin(PI/180*c);
    printf("%.4lf\n%.4lf\n%.4lf", s,l,h);
}