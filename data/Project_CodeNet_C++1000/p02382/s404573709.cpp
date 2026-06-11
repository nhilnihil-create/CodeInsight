#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n, i, ab, p1, p4 = 0;
    long p2, p3;
    cin >> n;
    int x[n], y[n];
    for (i = 0; i < n; i++) cin >> x[i];
    for (i = 0; i < n; i++) cin >> y[i];
    for (i = 0; i < n; i++) {
        ab = abs(x[i] - y[i]);
        p1 += ab;
        p2 += pow(ab, 2);
        p3 += pow(ab, 3);
        p4 = max(p4, ab);
    }
    cout << fixed << double(p1) << endl << sqrt(p2) << endl;
    cout << fixed << cbrt(p3) << endl << double(p4) << endl;
    return 0;
}