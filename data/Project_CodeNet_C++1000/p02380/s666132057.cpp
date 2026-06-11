#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x){
    return x * x;
}

int main(void){
    double a, b, C, rad;
    cin >> a >> b >> C;
    rad = C * M_PI / 180.0;
    cout << fixed << setprecision(8) << a * b * sin(rad) / 2 << endl;
    cout << fixed << setprecision(8) << a + b + sqrt(f(a) + f(b) - 2 * a * b * cos(rad)) << endl;
    cout << fixed << setprecision(8) << b * sin(rad) << endl;
    
    return 0;
}

