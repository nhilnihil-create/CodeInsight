#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long a, b;
    cin >> a >> b;

    long d = a / b;
    long r = a % b;
    double f = a * 100000 / b / 100000.0;
    cout << d << " ";
    cout << r << " ";
    cout << fixed << setprecision(5) << f << " " << endl;
    return 0;
}