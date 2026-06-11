#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, n) { cin >> a[i]; }
    ll s[n + 1];
    s[0] = 0;
    rep(i, n) { s[i + 1] = s[i] + a[i]; }
    ll judge[n + 1];
    rep(i, n + 1) { judge[i] = (s[i] - i) % k; }

    map<ll, ll> num;
    ll ans = 0;
    rep(i, n + 1) {
        ans += num[judge[i]];
        num[judge[i]]++;

        ll index = i - k + 1;
        if (index >= 0) {
            num[judge[index]]--;
        }
    }

    cout << ans << endl;
    return 0;
}

