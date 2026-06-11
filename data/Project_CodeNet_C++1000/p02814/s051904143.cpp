#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm2(ll a, ll b) {
    ll d = gcd(a, b);
    return a / d * b;
}

ll lcm(const vector<ll> &v) {
    ll l = v[0];
    for (int i = 0; i < v.size() - 1; i++) {
        l = lcm2(l, v[i + 1]);
    }
    return l;
}

int main() {
    ll n = 0, m = 0;
    ll a[100000];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> v;
    for (int i = 0; i < n; i++) {
        v.push_back(a[i] / 2);
    }

    ll l = lcm(v);
    
    for (int i = 0; i < n; i++) {
        if ((l / (a[i] / 2)) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    if (l > m) cout << 0 << endl;
    else if ((m / l) % 2 != 0) cout << (m / l) / 2 + 1 << endl;
    else cout << (m / l) / 2 << endl;
}