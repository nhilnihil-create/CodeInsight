#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double r;
    cin >> r;
    cout << fixed << setprecision(6) << r * r * M_PI << " " << 2 * r * M_PI << "\n";
}