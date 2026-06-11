#include <iostream>
using namespace std;

int gcd(int x, int y) {
    if (x == 0) {
        return y;
    } else if (y == 0) {
        return x;
    }
    if (x >= y) {
        return gcd(y, x%y);
    } else {
        return gcd(x, y%x);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}