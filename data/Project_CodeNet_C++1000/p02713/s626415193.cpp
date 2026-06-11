#include <bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; i++)
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
    int k;
    int sum = 0;
    cin >> k;
    rep(i, k) rep(j, k) rep(x, k) sum += gcd(i, gcd(j, x));
    cout << sum << endl;
    return 0;
}