#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> h(n+1);
    for(ll i=0; i<n; i++)
        cin >> h[i+1];

    vector<vector<ll>> dp(k+1, vector<ll>(n+1, 1e18));

    dp[0].assign(n, 0);
    for(ll i=1; i<=n; i++) {
        vector<vector<ll>> dq = dp;
        fill(dp.begin(), dp.end(), vector<ll>(n, 1e18));

        for(ll j=0; j<i; j++) {
            for(ll kk=0; kk<=k; kk++) 
                dp[kk][i] = min(dp[kk][i], max(0ll, h[i]-h[j]) + dq[kk][j]);
            for(ll kk=0; kk<k; kk++)
                dp[kk+1][j] = dq[kk][j];
        }
    }

    ll r = 1e18;
    for(ll kk=0; kk<=k; kk++)
        for(ll j=0; j<n+1; j++)
            r = min(r, dp[kk][j]);

    cout << r << endl;
}
