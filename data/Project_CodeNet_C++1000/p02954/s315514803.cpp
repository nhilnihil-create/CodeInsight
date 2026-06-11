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
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){

    string s;
    cin >> s;
    ll n = s.size();
    ll ans[n] = {};

    ll dp[21][n]; 
    rep(i,0,n) dp[0][i] = (s[i] == 'L' ? i-1 : i+1 );

    rep(i,1,21){
        rep(j,0,n){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    rep(i,0,n) ans[dp[20][i]]++;

    rep(i,0,n) cout << ans[i] << (i-n+1?" ":"");
    cout << endl;
    return 0;
}