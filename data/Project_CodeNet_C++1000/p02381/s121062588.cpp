#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {

    int n, s[1001];
    double a, m;

    for ( ;; ) {
        cin >> n;

        if ( n == 0 ) break;

        m = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            m += s[i];
        }
        m = m / n;    // ?????????

        a = 0;
        for (int i = 0; i < n; i++) {
            a += (s[i] - m) * (s[i] - m);
        }
        a = a / n;    // ?????£
        a = sqrt(a);    // ?¨??????????
        printf("%lf\n", a);
    }

    return 0;
}