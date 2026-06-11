#include <bits/stdc++.h>


using namespace std;


using ll = long long;


const ll INF = 1e9;


int main() {
    ll N, M;

    cin >> N >> M;
    vector<ll> price(M);
    vector<vector<ll>> keys(M);

    ll size = 1;
    for (ll i = 0; i < N; i++) {
        size *= 2;
    }
    vector<ll> dp(size, INF);

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        price[i] = a;
        for (ll j = 0; j < b; j++) {
            ll c;
            cin >> c;
            keys[i].push_back(c - 1);
        }
    }

    dp[0] = 0;
    for (ll i = 0; i < M; i++) {
        ll openable = 0;
        for (ll c : keys[i]) {
            openable |= (1LL << c);
        }

        for (ll bits = 0; bits < (1LL << N); bits++) {
            dp[bits | openable] = min(dp[bits | openable], dp[bits] + price[i]);
        }
    }

    if (dp[(1 << N) - 1] == INF) {
        dp[(1<< N) - 1] = -1;
    }
    cout << dp[(1 << N) - 1] << endl;
}
