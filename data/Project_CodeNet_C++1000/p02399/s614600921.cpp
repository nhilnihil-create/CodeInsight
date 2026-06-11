#include <iostream>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    double c = a * 1.0 / b;
    cout << a / b << ' ' << a % b << ' ' << fixed << c << endl;
    return 0;
}