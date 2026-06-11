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

    ll r = 0;
    ll t = 1;
    for (int i = 0; i <= n; i++) {
        r += t;
        t -= a[i];
        s -= a[i];
        if (t < 0) {
            cout << -1 << endl;
            exit(0);
        }
        t = min(t * 2, s);
    }

    cout << r << endl;

    return 0;
}