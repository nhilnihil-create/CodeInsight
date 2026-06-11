#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double a;
    cin >> a ;
    cout << fixed << setprecision(6) << 3.141592653589793*a*a << ' ' << 2*a*3.141592653589793 << endl;
    return 0;
}
