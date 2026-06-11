#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 1000;
    rep(i, n - 1) {
        ll pre = ans / a[i];
        if (a[i] < a[i + 1])
            ans += (a[i + 1] - a[i]) * pre;
    }

    cout << ans << endl;

    return 0;
}