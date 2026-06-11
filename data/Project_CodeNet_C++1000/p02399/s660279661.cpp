#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    int d;
    int r;
    double f;
    double da = (double) a;
    double db = (double) b;

    d = a / b;
    r = a % b;

    f = da / db; 
    cout << std::fixed << std::setprecision(6) << endl;
    cout << d << " " << r << " " << f << endl;

    return 0;
}