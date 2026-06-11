#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int n,i;
    long long S;
    double A,m;
    while (cin >> n && n) {
        int s[n];
        S = 0.0;
        for (i=0; i<n; i++) {
            cin >> s[i];
            S += s[i];
        }
        A = 0.0;
        m = (double) S/n;
        for (i=0; i<n; i++)
            A += (s[i] - m) * (s[i] - m);
        printf("%.8lf\n", sqrt(A/n));
    }
}
