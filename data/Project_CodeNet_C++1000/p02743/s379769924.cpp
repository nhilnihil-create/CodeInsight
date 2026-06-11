#include <iostream>
using namespace std;

bool check(long a, long b, long c) {
    long d = c - a - b;
    if (d <= 0) {
        return false;
    }
    if (d * d <= 4 * a * b) {
        return false;
    }
    return true;
}

int main() {
    long a, b, c;
    cin >> a >> b >> c;

    cout << (check(a, b, c) ? "Yes" : "No") << endl;

    return 0;
}