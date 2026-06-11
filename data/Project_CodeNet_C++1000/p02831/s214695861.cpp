#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
    if(x < y) swap(x, y);
    ll r;
    while(y > 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

ll lcm(ll x, ll y) {
    return ll(x / gcd(x, y)) * y;
}

int main() {
    ll A, B;
    cin >> A >> B;
    cout << (ll)lcm(A, B) << endl;
}