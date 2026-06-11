#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b,a);
    if (b == 0) return a;
    else return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a*b/gcd(a,b);}

ll f(ll x, ll c, ll d) {
    ll res = x;
    res -= x/c;
    res -= x/d;
    res += x/lcm(c,d);
    return res;
}

int main() {
    ll a, b;
    ll c, d;
    cin >>a >>b >>c >>d;
    ll ans = f(b, c, d) - f(a-1, c, d);
    cout << ans << endl;
    return 0;
}