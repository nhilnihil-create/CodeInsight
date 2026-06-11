#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<string, int>;

int main(void){
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> y[i];
    double a, b, c, mx;
    a = b = c = 0.0;
    mx = -1 * (1e9 + 7);
    rep(i, n){
        double v = abs(x[i] - y[i]);
        a += v;
        b += v * v;
        c += v * v * v;
        mx = max(mx, v);
    }
    b = sqrt(b);
    c = pow(c, 1.0 / 3.0);
    cout << fixed << a << endl << b << endl << c << endl << mx << endl;
    return 0;
}
