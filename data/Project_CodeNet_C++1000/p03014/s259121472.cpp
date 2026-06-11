#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


const ll MOD = 1e9+7;
 
signed main(){
    ll h,w;
    cin >> h >> w;
    char c[h][w];
    rep(i,0,h) rep(j,0,w) cin >> c[i][j];
    ll memo[h][w] = {};

    rep(i,0,h){
        ll cnt1 = 0,cnt2 = 0;
        rep(j,0,w){
            memo[i][j] += cnt1++;
            if(c[i][j] == '#') cnt1 = 0;

            memo[i][w-j-1] += cnt2++;
            if(c[i][w-j-1] == '#') cnt2 = 0;
        } 
    }
    rep(i,0,w){
        ll cnt1 = 0,cnt2 = 0;
        rep(j,0,h){
            memo[j][i] += cnt1++;
            if(c[j][i] == '#') cnt1 = 0;

            memo[h-j-1][i] += cnt2++;
            if(c[h-j-1][i] == '#') cnt2 = 0;
        } 
    }
    ll ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            if(c[i][j] == '#') continue;
            ans = max(ans,memo[i][j]);
        } 
    }

    cout << ans+1 << endl;
    return 0;
}
