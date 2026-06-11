#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, t;
    cin >> n >> t;

    vector<ll> a(n), b(n);
    rep(i, n)cin >> a[i] >> b[i];

    vector<ll> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](ll x, ll y){
        return a[x] < a[y];
    });

    // dp[i][j] : i個までで，j秒での満足度
    ll dp[n+1][t] = {};

    ll ans = 0;
    rep(i, n)rep(j, t){
        ll pos = ord[i];

        dp[i+1][j] = dp[i][j];
        // dp[i][j]とi+1
        ans = max(ans, dp[i+1][j] + b[pos]);
    
        ll order = j - a[pos];
        if(order >= 0){
            dp[i+1][j] = max(dp[i+1][j], dp[i][order] + b[pos]);
        }
    }

    cout << ans << endl;
}