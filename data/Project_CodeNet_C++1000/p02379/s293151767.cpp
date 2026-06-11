#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double ans = 0.0;
    double _x = fabs(x2 - x1);
    double _y = fabs(y2 - y1);
    ans = sqrt(pow(_x, 2) + pow(_y, 2));
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}