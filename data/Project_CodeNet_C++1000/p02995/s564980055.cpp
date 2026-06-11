#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    ll cn = b / c - a / c;
    ll dn = b / d - a / d;
    ll cd = lcm(c, d);
    ll cdn = b / cd - a / cd;
    cout << b - a - cn - dn + cdn << endl;
}