#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int main() {

    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    auto f = [&](ll x) {
        return x - x/c - x/d + x/lcm(c,d);
    };  

    cout << f(b) - f(a-1) << endl;
    return 0;
}