#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

int main(){
    ll h,n;
    cin >> h >> n;

    
    ll dp[n+1][h+1] = {};
    rep(i,0,n+1) rep(j,0,h+1) dp[i][j] = LINF;
    dp[0][0] = 0;

    ll a[n] = {},b[n] = {};
    rep(i,0,n) cin >> a[i] >> b[i];

    rep(i,0,n){
        rep(j,0,h+1){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            dp[i+1][min(h,j+a[i])] = min(dp[i+1][min(h,j+a[i])],dp[i+1][j] + b[i]);
        }
    }
    
    cout << dp[n][h] << endl;
    return 0;
}
