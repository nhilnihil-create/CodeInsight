#include <bits/stdc++.h>
#define FOR(i, begin, end) for(ll i = (begin); i < (end); i++)
#define rep(i, n) FOR(i, 0, n)
using ll = long long;
using namespace std;
#define all(x) (x).begin(),(x).end()
using pll = pair<ll, ll>; using vi = vector<int>; using vl = vector<ll>;
void chmax(ll& a, ll b) { a = max(a, b); }

ll n;
ll dp[2003][2003];

signed main() {
    cin >> n;
    vl a(n);
    rep(i,n) cin>>a[i];
    vector<pll> b(n);
    rep(i,n) b.emplace_back(a[i], i);
    sort(b.rbegin(), b.rend());

    FOR(i, 0, n) {
        ll ai = b[i].first;
        ll pi = b[i].second;
        FOR(l, 0, i+1) {
            ll r = i - l;
            chmax(dp[i+1][l+1], dp[i][l] + ai * (pi-l));
            chmax(dp[i+1][l], dp[i][l] + ai * ((n-r-1)-pi));

        }
    }
    ll ans = 0;
    rep(i,n) ans = max(ans, dp[n][i]);
    cout << ans;
    return 0;
}