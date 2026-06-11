
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<P> ps(m);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        ll p = 0;
        rep(j, b) {
            ll c;
            cin >> c;
            c--;
            p |= (1LL << c);
        }
        ps[i] = { a,p };
    }
    vector<vector<ll>> dp(2, vector<ll>(1LL << n, INF));
    dp[0][0] = 0;
    rep(i, m) {
        rep(j, 1LL << n) {
            chmin(dp[1][j], dp[0][j]);
            ll& t = dp[1][j | ps[i].second];
            chmin(t, dp[0][j] + ps[i].first);
        }
        swap(dp[0], dp[1]);
    }
    if (dp[0][(1LL << n) - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[0][(1LL << n) - 1] << endl;
    return 0;
}
