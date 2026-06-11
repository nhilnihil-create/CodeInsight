#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
    ll a, b, c, d, cd;
    cin >> a >> b >> c >> d;

    cd = c * d / __gcd(c, d);

    ll ic = a + (c - (a % c));
    if (a % c == 0)
        ic -= c;
    ll fc = b - (b % c);
    ll diff_c = fc - ic;

    ll tc = diff_c - diff_c / c;
    if (a % c != 0)
        tc += c - (a % c);
    tc += b % c;

    ll id = a + (d - (a % d));
    if (a % d == 0)
        id -= d;
    ll fd = b - (b % d);
    ll diff_d = fd - id;

    ll td = diff_d - diff_d / d;
    if (a % d != 0)
        td += d - (a % d);
    td += b % d;

    ll icd = a + (cd - (a % cd));
    if (a % cd == 0)
        icd -= cd;
    ll fcd = b - (b % cd);
    ll diff_cd = fcd - icd;

    ll tcd = diff_cd - diff_cd / cd;
    if (a % cd != 0)
        tcd += cd - (a % cd);
    tcd += b % cd;

    ll total = td + tc - tcd;
    cout << total << '\n';
}