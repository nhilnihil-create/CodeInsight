#include <iostream>
#include <cmath>

using namespace std;

#define int long long

signed main() {
    int a, b, c;
    cin >> a >> b >> c;

    int d = c - a - b;
    if(0 < d && 4 * a * b < d * d) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}