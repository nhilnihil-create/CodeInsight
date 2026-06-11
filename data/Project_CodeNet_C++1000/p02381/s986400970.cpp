#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n, s[1000];
    double sum, m, a;

    while (true) {
        cin >> n;

        if (n == 0) {
            return 0;
        }

        sum = a = 0;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            sum += s[i];
        }

        m = sum / n;

        for (int i = 0; i < n; i++) {
            a += (s[i] - m) * (s[i] - m);
        }
        a = sqrt(a / n);

        cout << fixed << setprecision(8) << a << endl;
    }
}