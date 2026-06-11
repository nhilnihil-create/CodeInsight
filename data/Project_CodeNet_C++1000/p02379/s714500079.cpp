#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout.precision(5);
    cout << fixed << hypot(x1-x2, y1-y2) << "\n";
    return 0;
}