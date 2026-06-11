#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    vector<ll> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];

    ll MOD = 1e9 + 7;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0)), sm(n+1, vector<ll>(m+1, 0));
    rep(i, n) rep(j, m){
        if(s[i] == t[j]){
            dp[i+1][j+1] = sm[i][j] + 1;
            dp[i+1][j+1] %= MOD;
        }
        sm[i+1][j+1] = sm[i][j+1] + sm[i+1][j] + MOD - sm[i][j] + dp[i+1][j+1];
        sm[i+1][j+1] %= MOD;
    }

    cout << (sm[n][m] + 1) % MOD << endl;
}
