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
    ll a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}
