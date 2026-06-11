#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// x1 * y2 - x2 * y1
using LL = long long;

int main() {
    LL S;
    cin >> S;
    LL k = sqrt(S);
    while (k * k < S) {
        k++;
    }
    LL w = k * k - S;
    cout << k << ' ' << w << ' ' << 1 << ' ' << k << ' ' << 0 << ' ' << 0 << endl;
    return 0;
}
