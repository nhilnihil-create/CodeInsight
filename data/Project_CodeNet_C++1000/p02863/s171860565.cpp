#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll dp[3010][3010];
ll N, T;
vector<P> v;

int main() {
    cin >> N >> T;
    v.resize(N);

    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        v[i] = P(a, b);
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            if (j + v[i].first < T) {
                dp[i + 1][j + v[i].first] = max(dp[i + 1][j + v[i].first], dp[i][j] + v[i].second);
            }
        }
        ans = max(ans, dp[i][T - 1] + v[i].second);
    }
    cout << ans << endl;
}