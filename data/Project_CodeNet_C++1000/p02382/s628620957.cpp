#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int i, n;
    cin >> n;
    double x[n], y[n], z[n], D1 = 0.0, D2 = 0.0, D3 = 0.0, Dinf = 0.0;

    for(i=0; i<n; ++i) {
        cin >> x[i];
    }
    for(i=0; i<n; ++i) {
        cin >> y[i];
    }

    for(i=0; i<n; ++i) {
        z[i] = abs(x[i] - y[i]);
    }
    for(i=0; i<n; ++i) {
        D1 += z[i];
        D2 += z[i] * z[i];
        D3 += z[i] * z[i] * z[i];
        Dinf = max(Dinf, z[i]);
    }
    D2 = sqrt(D2);
    D3 = pow(D3, 1.0 / 3.0);

    cout << fixed;
    cout.precision(5);
    cout << D1 << endl;
    cout << D2 << endl;
    cout << D3 << endl;
    cout << Dinf << endl;

    return 0;
}