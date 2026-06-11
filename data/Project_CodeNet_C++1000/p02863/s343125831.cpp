#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, T;
// vector<ll> A, B;

vector<P> v;

// i: 何個目
// j: 注文した時間

ll dp[3010][6020];
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

    // i 番目を最後とする
    for (int i = 0; i < N; i++) {

        // T 未満だったら、次の料理が選べる
        for (int j = 0; j < T; j++) {
            // 選ばない
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            // 選ぶ
            dp[i + 1][j + v[i].first] = max(dp[i + 1][j], dp[i][j] + v[i].second); 
        }

        ans = max(ans, dp[i][T - 1] + v[i].second);
    }

    cout << ans << endl;
}