#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;

vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

ll calc(ll a, ll b) {
    return a * a * a * a * a - b * b * b * b * b;
}

int main() {
    ll X;
    cin >> X;

    vector<ll> dsrs = divisor(X);
    for (auto dr : dsrs) {
        // 65^5 = 1160290625
        for (ll b = -65; true; b++) {
            ll a = b + dr;
            // 120^5 - 119^5 = 1019663401
            if (a > 120) {
                break;
            }
            if (calc(a, b) == X) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}
