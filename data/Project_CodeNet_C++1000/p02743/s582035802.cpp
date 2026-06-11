#include <iostream>
using namespace std;

bool check(long a, long b, long c) {
    long d = c - a - b;
    return d > 0 && d * d > 4 * a * b;
    //     if (d <= 0) {
    //         return false;
    //     }
    //     if (4 * a * b >= d * d) {
    //         return false;
    //     }
    //     return true;
}

int main() {
    long a, b, c;
    cin >> a >> b >> c;

    cout << (check(a, b, c) ? "Yes" : "No") << endl;

    return 0;
}