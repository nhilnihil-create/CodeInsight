#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n; cin >> n;

    vector<ll> a(n);
    vector<ll> s(n+1, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }

    ll t = s[n] / 2;

    ll ans = LINF;

    ll m = 0;

    for (ll i = 0; i < n+1; ++i) {
        if (s[i] >= t) {
            m = i;
            break;
        }
    }

    ans = min(ans, abs(s[m] - t) + abs((s[n] - s[m]) - t));
    ans = min(ans, abs(s[m-1] - t) + abs((s[n] - s[m-1]) - t));

    cout << ans << endl;
}