#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main () {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        double ss[n];
        for (int i=0; i<n; i++) {
            cin >> ss[i];
        }
        double sum = 0.0;
        for (int i=0; i<n; i++) sum += ss[i];

        double ave = sum / (double)n;

        double compare = 0;
        for (int i=0; i<n; i++) compare += pow(ss[i] - ave, 2);
        double a = sqrt(compare / (double)n);
        printf("%lf\n", a);
    }
    return 0;
}