#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll numbers = b - a + 1;
    ll div_c = (numbers / c) + ((b % c == 0) && (a % c == 0));
    ll div_d = (numbers / d) + ((b % d == 0) && (a % d == 0));

    ll num_c = b/c - (a-1) / c;
    ll num_d = b/d - (a-1) / d;
    c = c * d / (__gcd(c, d));

    ll num_cd = b/c - (a-1)/c;
    cout << numbers - (num_c + num_d - num_cd) << endl;
}