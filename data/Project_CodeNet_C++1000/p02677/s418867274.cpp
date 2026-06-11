#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    long double rad;
    rad = 2.0 * M_PI *
          ((long double)h / 12.0 + ((long double)m / 60.0) / 12.0 -
           (long double)m / 60.0);

    long double rsq;
    rsq = (long double)(a * a + b * b) - (long double)(2 * a * b) * cosl(rad);
    printf("%20.20Lf\n", sqrtl(rsq));
    // cout << sqrtl(rsq) << endl;

    return 0;
}