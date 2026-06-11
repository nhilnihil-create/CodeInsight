#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
    ll t[2], a[2], b[2];
    cin >> t[0] >> t[1] >> a[0] >> a[1] >> b[0] >> b[1];

    if (a[0] < b[0]) swap(a[0], b[0]), swap(a[1], b[1]);

    if (a[0] * t[0] - b[0] * t[0] == b[1] * t[1] - a[1] * t[1]) {
        cout << "infinity" << endl;
        return 0;
    }

    if (a[0] * t[0] + a[1] * t[1] > b[0] * t[0] + b[1] * t[1]) {
        cout << 0 << endl;
        return 0;
    }

    ll diff = t[0] * (b[0]-a[0]) + t[1] * (b[1]-a[1]);

    ll diffA = t[0] * (a[0]-b[0]);

    ll res = 1;
    res += 2 * ((diffA-1)/diff);
    if (diffA%diff == 0) ++res;
    cout << res << endl;
}
