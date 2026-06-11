#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x){
    return x * x;
}
int main(void){
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(8) << sqrt(f(x2 - x1) + f(y2 - y1)) << endl;
    
    return 0;
}

