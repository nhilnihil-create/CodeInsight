#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    double a,b,c,s,l,h;
    cin >> a >> b >> c;
    s = a*b*sin(c*M_PI/180)/2;
    l = a+b+sqrt(a*a+b*b-2*a*b*cos(c*M_PI/180));
    h = s*2/a;
    cout << fixed << setprecision(6)<< s << endl << l << endl << h << endl;
    return 0;
}