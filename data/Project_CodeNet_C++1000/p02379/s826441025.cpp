
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double calDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(4) << calDistance(x1, y1, x2, y2) << endl;

    return 0;
}