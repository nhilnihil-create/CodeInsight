#include <iostream>
#include <algorithm>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;

ll gcd(ll x, ll y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ll a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    ll g = gcd(a, b);
    a /= g; b /= g;
    ll lcm = g * a * b;
    cout << lcm << endl;

    return 0;
}
