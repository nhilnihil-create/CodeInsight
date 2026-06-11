#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
    double x1, y1, x2, y2, dis;
    cin >> x1 >> y1 >> x2 >> y2;
    double x = x1 - x2, y = y1 - y2;
    dis = sqrt(x * x + y * y);
    cout << setprecision(10) << dis << endl;
    return 0;
}
