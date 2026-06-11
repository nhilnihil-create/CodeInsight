#include <iostream>
#include "math.h"

#define PI 3.141592653589793

using namespace std;
int main(int argc, const char * argv[]) {
    
    double a,b,C,S,L,h,rad;
    cin >> a >> b >>C;
    rad = C * PI / 180.0;
    
    
    S = (a*b*sin(rad))/2.0;
    L = a + b + sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(rad)));
    h =  b * sin(rad);
    
    cout.precision(15);
    cout << S << endl;
    cout << L << endl;
    cout << h << endl;
    
    return 0;
}