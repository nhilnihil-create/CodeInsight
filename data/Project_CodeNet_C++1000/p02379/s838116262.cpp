#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int main() {
    double a, b, c, d;
    cin >> a >> b >> c >>d;
    double x = (a - c)*(a - c);
    double y = (b - d) *(b - d);

    cout << fixed << setprecision(10) << sqrt(x + y) << endl;

    return 0;
}
