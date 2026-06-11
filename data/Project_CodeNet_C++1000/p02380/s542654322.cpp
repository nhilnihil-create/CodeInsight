#include <bits/stdc++.h>
using namespace std;

int main() {
    static const double pi = 3.141592653589793;
    double a, b, c;
    cin >> a >> b >> c;
    
    double s, l, h;
    
    s = a * b * sin(c * pi / 180.0) / 2.0;
    cout << fixed << setprecision(cout.precision()) << s << endl;
    
    l = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(c * pi / 180.0));
    cout << fixed << setprecision(cout.precision()) << l << endl;
    
    h = b * sin(c * pi / 180.0);
    cout << fixed << setprecision(cout.precision()) << h << endl;
    
    return 0;
}
