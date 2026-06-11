#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double a, b, c;
    cin >> a >> b >> c;
    double h = b * sin(M_PI * c / 180);
    double a_ = b * cos(M_PI * c / 180);
    double s = a * h / 2;
    double l = a + b + sqrt(h*h + (a-a_)*(a-a_));
    cout << fixed << setprecision(8) << s << " " << l << " " << h << "\n";
}