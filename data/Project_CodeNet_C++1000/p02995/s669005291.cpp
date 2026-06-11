#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    --a;
    long long sa = a / c + a / d - a / lcm(c, d);
    long long bb = b / c + b / d - b / lcm(c, d);
    cout << (b - bb) - (a - sa) << endl;
    return 0;
}