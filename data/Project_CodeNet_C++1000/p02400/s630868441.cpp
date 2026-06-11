#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    double r;
    cin >> r;

    double f = M_PI * r * r;
    double g = 2 * M_PI * r;
    cout << fixed << setprecision(6) << f << " ";
    cout << fixed << setprecision(6) << g << endl;
    return 0;
}