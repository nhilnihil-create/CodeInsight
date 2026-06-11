#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    long double l;
    cin >> l;
    cout << fixed;
    cout << setprecision(8);
    cout << (l/3.0)*(l/3.0)*(l/3.0) << endl;
}