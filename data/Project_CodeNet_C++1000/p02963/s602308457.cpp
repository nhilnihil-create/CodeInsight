#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll s; cin >> s;

    ll a, b, c, d;
    a = 1e9; b = 1;

    // s = a * d - c
    d = ceil((double)s / (double)a);
    c = a * d - s;

    cout << "0 0 " << a << " " << b << " " << c << " " << d << endl;
}