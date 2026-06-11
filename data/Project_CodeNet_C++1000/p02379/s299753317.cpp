#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main(){
    double a, b, c, d;
    double x, y, n;
    cin >> a >> b >> c >> d;
    
    x = a - c;
    y = b - d;
    
    x = pow(x, 2);
    y = pow(y, 2);
    
    n = x + y;
    n = sqrt(n);
    
    cout << fixed;
    cout << setprecision(6) << n;
}

