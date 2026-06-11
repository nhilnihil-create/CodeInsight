#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)

void chmax(ll& a, ll b) { a = max(a, b); }
void chmin(ll& a, ll b) { a = min(a, b); }

using P = pair<ll, ll>;
const ll INF = 1e18;

ll dp[2005][2005];


int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    rep(i, 2005) rep(j, 2005) dp[i][j] = -INF;
    dp[0][0] = 0;

    vector<P> p;
    rep(i, n) p.emplace_back(a[i], i);
    sort(p.rbegin(), p.rend());
    rep(i, n) {
        int pi = p[i].second;
        rep(l, i+1) {
            int r = i-l;
            chmax(dp[i+1][l+1], dp[i][l] + ll(pi-l)*a[pi]);
            chmax(dp[i+1][l], dp[i][l] + ll((n-r-1)-pi) * a[pi]);
        }
    }

    ll ans = 0;
    rep(i, n+1) chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}