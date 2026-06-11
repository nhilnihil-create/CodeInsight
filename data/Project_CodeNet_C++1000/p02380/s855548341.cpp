#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    // Here your code !
    double PI = 3.141592653589793;
    int a, b;
    double c;
    cin >> a >> b >> c;
    c = c * PI / 180;
    double s, l, h;
    s = a*b/2 * sin(c);
    l = a + b + sqrt(a*a + b*b - 2*a*b*cos(c));
    h = s * 2 / a;
    cout << fixed
         << setprecision(5)
         << s << endl
         << l << endl
         << h << endl;
}