
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <complex>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double c = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 -y2);
    c = sqrt(c);
    cout << fixed << setprecision(6) << c << endl;


}

