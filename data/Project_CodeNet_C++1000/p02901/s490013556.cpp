#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

const ll INF = 100100100100;

int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> dp(m+1,vector<ll>(1<<n,INF));
    dp[0][0] = 0;
    rep(i,m){
        ll a, b; cin >> a >> b;
        ll count = 0;
        rep(j,b){
            ll c; cin >> c;
            count |= 1<<(c-1);
        }
        rep(j,1<<n){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            dp[i+1][j|count] = min(dp[i+1][j|count],dp[i][j]+a);
        }
    }
    if(dp[m][(1<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[m][(1<<n)-1] << endl;
}