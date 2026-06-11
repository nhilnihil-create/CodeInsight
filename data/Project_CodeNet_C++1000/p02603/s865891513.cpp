#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 1000;
    ll kabu = 0;

    for (ll i = 0; i < n - 1; ++i) {
        if (a[i] < a[i + 1] && kabu == 0) {
            // 買う
            kabu = ans / a[i];
            ans -= ans / a[i] * a[i];
            continue;
        }

        if (a[i] > a[i + 1] && kabu > 0) {
            // 売る
            ans += kabu * a[i];
            kabu = 0;
            continue;
        }
    }

    if (kabu > 0) {
        ans += kabu * a[n - 1];
    }

    cout << ans << endl;
}