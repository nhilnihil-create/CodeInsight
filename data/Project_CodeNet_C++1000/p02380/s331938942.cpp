#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    double a, b, c, C, S, L, h;
    double PI = 3.14159265;
    cin >> a >> b >> C;
    S = a * b / 2 * sin(C * PI / 180);
    c = sqrt(a*a + b*b - 2*a*b*cos(C * PI / 180));
    L = a + b + c;
    h = 2 * S / a;
    cout << fixed;
    cout << setprecision(8) << S << endl;
    cout << L << endl;
    cout << h << endl;
    return 0;
}

