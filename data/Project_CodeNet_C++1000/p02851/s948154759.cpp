#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<ll> dp(n + 1, 0);
    rep(i, n) dp[i + 1] = (dp[i] + a[i]) % k;
    map<ll, vector<ll>> idx;
    rep(i, n) idx[dp[i + 1]].push_back(i + 1);
    ll ans = 0;
    rep(i, n) {
        ll cnt1 = sz(idx[dp[i]]) - (upper_bound(all(idx[dp[i]]), i) - idx[dp[i]].begin());
        ll cnt2 = sz(idx[dp[i]]) - (lower_bound(all(idx[dp[i]]), i + k) - idx[dp[i]].begin());
        ans += cnt1 - cnt2;
    }
    cout << ans << endl;
    return 0;
}
