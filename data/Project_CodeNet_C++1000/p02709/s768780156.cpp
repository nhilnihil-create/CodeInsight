#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


vector<P> vp;
ll dp[2010][2010];

int main(){
    ll n;
    cin >> n;
    rep(i, n){
        ll a;
        cin >> a;
        vp.push_back({a,i});
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    
    rep(i, n + 1){
        for (int j = 0; j + i <= n; j++){
            ll cl = vp[i+j].first * (vp[i+j].second - i);
            ll cr = vp[i+j].first * (n - j - 1 - vp[i+j].second);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + cl);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j] + cr);
        }
    }

    ll ans = 0;
    rep(i, n) ans = max(ans, dp[i][n-i]);

    cout << ans << endl;

    return 0;
}
