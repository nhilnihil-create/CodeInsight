#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i, n + 1) cin >> a[i];
    if (n == 0) {
        if (a[0] == 1) {
            cout << 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
        return 0;
    }
    vector<ll> dp(n + 2, 0);
    rrep(i, n + 1) dp[i] += dp[i + 1] + a[i];
    ll ans = 0, cv = 1;
    rep(i, n + 1) {
        if (cv < a[i]) {
            cout << -1 << endl;
            return 0;
        }
        cv = min(cv, dp[i]);
        ans += cv;
        cv -= a[i];
        cv *= 2;
    }
    cout << ans << endl;
    return 0;
}
