#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
// a x + b y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a;
    x = 1;
    y = 0;
    if(b != 0)
        g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    ll num;
    num = lcm(c, d);
    ll w, x, y, z;
    w = b / c;
    x = (a - 1) / c;
    y = b / d;
    z = (a - 1) / d;
    ll e, f;
    e = b / num;
    f = (a - 1) / num;
    cout << b - a + 1 - w + x - y + z + e - f << endl;

    return 0;
}