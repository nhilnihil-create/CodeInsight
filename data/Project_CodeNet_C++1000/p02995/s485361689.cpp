#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll div_c, div_d, div_cd;
    div_c = b / c - (a - 1) / c;
    div_d = b / d - (a - 1) / d;
    ll cd = 1;
    cd = c * d / gcd(c, d);
    div_cd = b / cd - (a - 1) / cd;
    cout << b - a + 1 - div_c - div_d + div_cd << endl;
    return 0;
}