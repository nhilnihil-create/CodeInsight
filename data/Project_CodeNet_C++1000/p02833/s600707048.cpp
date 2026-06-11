#include <iostream>
#include <algorithm>
using namespace std;
using llong = long long;

int main() {
    llong n;
    llong s2 = 0;
    llong s5 = 0;

    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    llong s = n;
    while (s > 0) {
        s2 += s / 2;
        s /= 2;
    }

    s = n;
    while (s > 0) {
        s5 += s / 10;
        s /= 5;
    }

    cout << min(s2, s5) << endl;

    return 0;
}
