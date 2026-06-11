#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        a[i] = x + y;
        b[i] = x - y;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << max(a[n - 1] - a[0], b[n - 1] - b[0]) << '\n';
    return 0;
}