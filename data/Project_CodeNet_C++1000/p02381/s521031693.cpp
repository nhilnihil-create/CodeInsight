#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n, s[1000];

    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i];
        }
        double m = 1.0 * sum / n;

        double t = 0;
        for (int i = 0; i < n; i++) {
            t += (s[i] - m) * (s[i] - m);
        }

        double a = sqrt(t / n);
        printf ("%.6f\n", a);
    }

    return 0;
}