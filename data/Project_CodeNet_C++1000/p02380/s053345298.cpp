#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    double a, b, C;
    cin >> a >> b >> C;
    
    double S, L, h;
    
    S = 0.50 * a * b * sin(C * M_PI / 180.0);
    L = a + b + sqrt(a*a + b*b - 2.0*a*b*cos(C * M_PI / 180.0));
    h = b * sin(C * M_PI / 180.0); 
    
    
    cout << fixed << S << " " << L << " " << h;
    
    return 0;
}