#include <iostream>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

ll pri(ll x) {
    ll mx = 1;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) mx = i;
    }
    return mx;
}

int main() {
    ll n;
    cin >> n;
    ll a = pri(n);
    ll b = n / a;
    cout << a + b - 2;
}