#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N), C(N);
    for ( int i = 0; i < N; i++ ) cin >> P[i], P[i]--;
    for ( int i = 0; i < N; i++ ) cin >> C[i];

    vector<int> gp(N,-1);
    int g = 0;
    vector<ll> gp_len, gp_sum;
    for ( int i = 0; i < N; i++ ) {
        if ( gp[i] >= 0 ) continue;
        int cur = i;
        while ( gp[cur] < 0 ) {
            gp[cur] = g;
            if ( gp_len.size() <= g ) gp_len.push_back(0LL);
            if ( gp_sum.size() <= g ) gp_sum.push_back(0LL);
            gp_len[g]++;
            gp_sum[g] += C[cur];
            cur = P[cur];
        }
        g++;
    }
    ll ans = -1e10;
    for ( int i = 0; i < N; i++ ) {
        int g = gp[i];
        int cur = i;
        ll k = K;
        ll s = 0;
        for ( int j = 0; j < min(gp_len[g],K); j++ ) {
            cur = P[cur];
            s += C[cur];
            k--;
            ll x = s + k/gp_len[g]*max(gp_sum[g],0LL);
            ans = max(ans, x);
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}