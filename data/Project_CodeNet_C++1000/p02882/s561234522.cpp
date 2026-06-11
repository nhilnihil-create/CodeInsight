#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    double a, b, x; cin >> a >> b >> x;
    x /= a;
    double theta;
    if (a * b < 2 * x) {
        theta = atan2(2 * (a * b - x), a * a);
    } else {
        theta = M_PI / 2 - atan2(2 * x, b * b);
    }
    cout << fixed << setprecision(12);
    cout << theta * 180 / M_PI << endl;
}