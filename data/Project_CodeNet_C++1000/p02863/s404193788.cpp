#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main() {
    ll N, T;
    cin >> N >> T;
    vector<pair<ll, ll>> foods(N + 1);
    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        foods[i + 1] = make_pair(a, b);
    }

    vector<vector<ll>> dp1(N + 2, vector<ll>(T + 1, 0));
    vector<vector<ll>> dp2(N + 2, vector<ll>(T + 1, 0));

    for (ll n = 1; n <= N; n++) {
        for (ll t = 0; t < T; t++) {
            dp1[n][t] = max(
                            dp1[n - 1][t],
                            t - foods[n].first >= 0 ? dp1[n - 1][t - foods[n].first] + foods[n].second : 0
                    );
        }
    }

    for (ll n = N; n >= 1; n--) {
        for (ll t = 0; t < T; t++) {
            dp2[n][t] = max(
                            dp2[n + 1][t],
                            t - foods[n].first >= 0 ? dp2[n + 1][t - foods[n].first] + foods[n].second : 0
                    );
        }
    }

    vector<ll> score(N + 1, 0);
    for (ll n = 1; n <= N; n++) {
        for (ll t = 0; t < T; t++) {
            score[n] = max(score[n], dp1[n - 1][t] + dp2[n + 1][T - t - 1] + foods[n].second);
        }
    }

    ll ans = *max_element(score.begin(), score.end());
    cout << ans << endl;
}
