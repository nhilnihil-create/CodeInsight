#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int main() {
    while(1) {
        int n;
        cin >> n;
        if (n == 0) break;
        int S[n];
        for (int i = 0; i < n; i++) cin >> S[i];
        double m = 0;
        for (int i = 0; i < n; i++) m += S[i];
        m /= n;
        double a = 0;
        for (int i = 0; i < n; i++) a += (S[i] - m) * (S[i] - m);
        a /= n;
        a = sqrt(a);
        printf("%.5lf\n", a);
        // cout << a << endl; 
    }
    return 0;
}
