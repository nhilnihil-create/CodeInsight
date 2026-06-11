#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll dp[3005][3005];

int main(){
    int n, t;
    cin >> n >> t;
    vector<P> a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    rep(i, n) {
        rep(j, t) {
            if (i==0) {
                if (j==a[i].first) dp[i][j] = a[i].second;
                continue;
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j-a[i].first>=0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-a[i].first]+a[i].second);
            }
        }
    }
    ll ans = a[0].second;
    rep(i, n-1) {
        ll res = 0;
        rep(j, t) {
            res = max(res, dp[i][j]);
        }
        ans = max(ans, res+a[i+1].second);
    }    
    
    
    
    cout << ans << endl;
    return 0;
}
