#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef valarray<double> vad;

int main(){
    int n;
    cin >> n;
    vad x(n), y(n);
    REP(i, n) cin >> x[i];
    REP(i, n) cin >> y[i];
    double d1, d2, d3, di;
    vad tmp = abs(x-y);
    di = tmp.max();
    d1 = tmp.sum();
    vad tmp2 = tmp * tmp;
    d2 = sqrt(tmp2.sum());
    tmp *= tmp2;
    d3 = cbrt(tmp.sum());
    cout << fixed << setprecision(5)
    << d1 << endl << d2 << endl << d3 << endl << di << endl;
}