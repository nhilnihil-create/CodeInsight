#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, M;
vector<ll> a, b;

vector<P> keys;


int main() {
    cin >> N >> M;
    a.resize(M);
    b.resize(M);

    rep(i, M) {
        cin >> a[i] >> b[i];

        ll s = 0;
        rep(j, b[i]) {
            ll tmp_c;
            cin >> tmp_c;
            tmp_c--;
            s |= (1LL << tmp_c);
        }

        keys.push_back(P(s, a[i]));  
    }

    vector<ll> dp(1 << N, INF);
    dp[0] = 0;

    rep(s, 1 << N) {
        rep(i, M) {
            ll to = s | keys[i].first; 
            ll cost = dp[s] + keys[i].second;
            dp[to] = min(dp[to], cost);
        }
    }

    // 一番後ろの要素
    ll ans = dp.back();
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}