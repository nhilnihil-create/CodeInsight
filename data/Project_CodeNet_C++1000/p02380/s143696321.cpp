#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main(){
    int a, b, C;
    cin >> a >> b >> C;
    double S, L, h;
    h = b * sin(C * M_PI / 180.0);
    S = a * h / 2.0;
    L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C *M_PI / 180.0));
    cout << fixed << setprecision(5);
    cout << S << endl;
    cout << L << endl;
    cout << h << endl;
}