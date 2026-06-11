#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {

    for (;;) {
        int n;
        cin >> n;

        if (n == 0) break;
        int *s = new int[n];

        double m = 0.0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            m += s[i];
        }
        m /= n;

        double sigma = 0.0;
        for (int i = 0; i < n; ++i) {
            sigma += pow(s[i] - m, 2);
        }
        sigma /= n;
        sigma = sqrt(sigma);

        cout << fixed << setprecision(7) << sigma << endl;
        delete[] s;
    }

    return 0;
}