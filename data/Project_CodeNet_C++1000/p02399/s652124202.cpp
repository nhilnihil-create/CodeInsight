#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main () {
    int a, b;
    double A, B;
    cin >> a >> b;

    A = a;
    B = b;

    cout << fixed;
    cout << a / b << " " <<  a % b << " " << setprecision(9) <<  A / B << endl;

    return 0;
}
