#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    long long c = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 2;
        if (c <= m) {
            c = (c*a[i]) / __gcd(c, a[i]);
        }
    }
    bool ok = true;
    for (auto v: a) {
        if ((c/v) % 2 == 0) {
            ok = false;
        }
    }
    long long ans = 0;
    if (ok) {
        ans = (m/c + 1)/2;
    }
    cout << ans << endl;
}

