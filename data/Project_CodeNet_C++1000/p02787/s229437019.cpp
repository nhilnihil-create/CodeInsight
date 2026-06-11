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
ll dp[1001][20001]; 

int main(){
    ll h,n;
    cin >> h >> n;
    ll a[n] = {},b[n] = {};
    rep(i,0,n){
        cin >> a[i] >> b[i];
    }

    
    rep(i,0,n){
        rep(j,1,20001){
            dp[i][j] = LINF;
        }
    }

    rep(i,0,n){
        rep(j,0,20001){
            if(a[i] <= j) dp[i+1][j] = min(dp[i+1][j-a[i]] + b[i], dp[i][j]);
            else dp[i+1][j] = dp[i][j];
        }
    }
    
    ll ans = LINF;
    rep(i,h,20001){
        ans = min(ans,dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
