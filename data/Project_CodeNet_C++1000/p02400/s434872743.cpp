#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {

    double r;
    double e, m;
    cin >> r;
    
    e = (r + r) * M_PI;
    m = (r * r) * M_PI;
    
    cout << setprecision(6);
    cout << fixed << m << " " << e << endl;
    
    return 0;
}