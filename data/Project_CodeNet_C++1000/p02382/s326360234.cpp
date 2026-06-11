#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    double d[4];
    valarray<double> x(n), y(n);
    REP(i, n) cin >> x[i];
    REP(i, n) cin >> y[i];
    x = abs(x-y);
    d[3] = x.max();
    d[0] = x.sum();
    y = x * x;
    d[1] = sqrt(y.sum());
    x *= y;
    d[2] = cbrt(x.sum());
    REP(i, 4) cout << fixed << setprecision(5) << d[i] << endl;
}