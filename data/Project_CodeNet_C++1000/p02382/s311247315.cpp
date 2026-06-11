#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)

int main() {
    int n;
    cin >> n;
    int x[n] = {};
    int y[n] = {};

    REP(i, n) cin >> x[i];
    REP(i, n) cin >> y[i];

    double d[4] = {};
    FOR(p, 1, 4) {
        REP(i, n) d[p] += pow(fabs(x[i] - y[i]), p);
        d[p] = pow(d[p], 1.0 / p);
    }

    REP(i, n) {
        d[0] =max(d[0], fabs(x[i] - y[i]));
        //d[0] = (d[0] < fabs(x[i] - y[i]) ? fabs(x[i] - y[i]) : d[0]);
    }

    printf("%lf\n", d[1]);
    printf("%lf\n", d[2]);
    printf("%lf\n", d[3]);
    printf("%lf\n", d[0]);
}