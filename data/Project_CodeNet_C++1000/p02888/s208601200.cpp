#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    sort(d.begin(), d.end());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int k = lower_bound(d.begin() + j + 1, d.end(), d[i] + d[j]) - d.begin();
            ans += max(k - j - 1, 0);
        }
    }

    cout << ans << endl;

    return 0;
}