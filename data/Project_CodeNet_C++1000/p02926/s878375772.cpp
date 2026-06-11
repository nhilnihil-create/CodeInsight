#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
using namespace std;

using ll = long long;
using boost::irange;

#define PI 3.14159

int main(){
    int N;

    cin >> N;

    vector<ll> X(720, 0), Y(720, 0);

    ll x, y;
    double ip;
    for (int i : irange(0, N)){
        cin >> x >> y;

        for (int j : irange(0, 720)){
            ip = cos(j * PI / 360) * x + sin(j * PI / 360) * y;
            if (ip > 0.0) {
                X[j] += x;
                Y[j] += y;
            }
        }
    }

    double r;
    double r_max = 0;
    for (int i : irange(0, 720)) {
        r = sqrt(X[i] * X[i] + Y[i] * Y[i]);
        if (r > r_max) r_max = r;
    }

    cout << std::fixed;
    cout << std::setprecision(15) << r_max << endl;

    return 0;


}