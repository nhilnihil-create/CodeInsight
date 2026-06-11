#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        x[i] = b[i] - a[i] + 1;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 0) {
        ll mi = a[n / 2 - 1] + a[n / 2];
        ll ma = b[n / 2 - 1] + b[n / 2];
        cout << ma - mi + 1 << endl;
    } else {
        ll mi = a[n / 2];
        ll ma = b[n / 2];
        cout << ma - mi + 1 << endl;
    }
    return 0;
}