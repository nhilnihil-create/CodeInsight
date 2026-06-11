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
    ll n, m;
    cin >> n >> m;

    ll a[m], bit[m];
    rep(i, m){
        ll b;
        cin >> a[i] >> b;

        bit[i] = 0;
        rep(j, b){
            ll c;
            cin >> c;
            c--;
            bit[i] += 1LL << c;
        }
    }

    // dp[i][bit] : iつめまでの鍵を使い,bitの箱を開ける最小値
    ll dp[m+1][1LL<<n];
    rep(i, m+1)rep(j, 1LL<<n)dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i, m)rep(j, 1LL<<n){
        // 使わない場合
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        // 使う場合
        ll bor = bit[i] | j;
        dp[i+1][bor] = min(dp[i+1][bor], dp[i][bor]);
        dp[i+1][bor] = min(dp[i+1][bor], dp[i][j] + a[i]);
    }

    ll ans = dp[m][(1LL<<n)-1];
    if(ans >= INF)cout << -1 << endl;
    else cout << ans << endl;
}