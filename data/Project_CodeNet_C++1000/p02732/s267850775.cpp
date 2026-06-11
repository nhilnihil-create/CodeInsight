#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

ll f(int n) {
    if (n < 2) return 0;
    return (ll)n * (n-1) / 2;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(n+1);
    rep(i, n) {
        cin >> a[i];
        c[a[i]]++;
    }
    ll sum = 0;
    rep(i, n+1) {
        sum += f(c[i]);
    }
    rep(i, n) {
        ll ans = sum - (c[a[i]] - 1);
        cout << ans << endl;
    }
}