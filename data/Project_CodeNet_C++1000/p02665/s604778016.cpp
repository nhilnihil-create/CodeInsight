#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    ll s = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }

    vector<ll> b(n + 1);
    ll t = 1;
    for (int i = 0; i <= n; i++) {
        t -= a[i];
        s -= a[i];
        if (t < 0) {
            cout << -1 << endl;
            exit(0);
        }
        b[i] = t = min(t, s);
        t *= 2;
    }

    ll r = 0;
    for (int i = n; i >= 0; i--) {
        ll t = a[i] + b[i];
        r += t;
        if (i == 0) break;
        if (t < b[i - 1]) b[i - 1] = t;
    }

    cout << r << endl;

    return 0;
}