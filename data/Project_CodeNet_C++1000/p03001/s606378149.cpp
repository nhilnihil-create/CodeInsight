#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const ld eps = 1e-9;

int main() {
    ld w, h, x, y;
    cin >> w >> h >> x >> y;
    ld temp = w * h * 0.5;
    cout << temp << " ";
    cout << (abs(w/2 - x) <= eps && abs(h/2 - y) <= eps) << endl;
}