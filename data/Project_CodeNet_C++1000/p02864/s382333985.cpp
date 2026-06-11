#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;
const ll INF = 1E+18;

ll dp[305][305];

ll max(ll a, ll b) {
    if (a>b) return a;
    else return b;
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n+1);
    h[0] = 0;
    rep(i, n) cin >> h[i+1];
    ll sum = 0;
    rep(i, n+1) {
        if (i==0) continue;
        sum += max(0, h[i]-h[i-1]);
    }

    
    rep(i, 305) rep(j, 305) dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (j==1) {
                dp[i][j] = h[i];
                continue;
            }
            for (int l=0; l<i; l++) {
                dp[i][j] = min(dp[i][j], dp[l][j-1]+max(0, h[i]-h[l]));
            }
        }
    }

    ll ans = INF;
    rep(i, n+1) {
        ans = min(ans, dp[i][n-k]);
    }
    
    
    
    cout << ans << endl;
    return 0;
}
