#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    cout << fixed << setprecision(8) << d << "\n";
}