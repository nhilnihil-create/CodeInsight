#include <iostream>

using namespace std;

int main() {
    long long a, b, m;
    cin >> m;

    for (a = -1000; a < 1001; a++) {
        for (b = -1000; b < 1001; b++) {
            long long x = 0;
            x += a*a*a*a*a;
            x -= b*b*b*b*b;
            if (x == m) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}