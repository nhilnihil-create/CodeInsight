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
    ll h,w;
    cin >> h >> w;
    char c[h][w] = {};
    rep(i,0,h) rep(j,0,w) cin >> c[i][j];

    ll dp[h+1][w+1] = {};
    rep(i,0,h+1) rep(j,0,w+1) dp[i][j] = LINF;
    dp[0][0] = 0;

    rep(i,0,h){
        rep(j,0,w){
            if(i < h-1 && c[i][j] == '#' && c[i+1][j] == '.') dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1);
            else dp[i+1][j] = min(dp[i+1][j],dp[i][j]);

            if(j < w-1 && c[i][j] == '#'&& c[i][j+1] == '.') dp[i][j+1] = min(dp[i][j+1],dp[i][j]+1);
            else dp[i][j+1] = min(dp[i][j+1],dp[i][j]);
        }
    }

    if(c[h-1][w-1] != '#') cout << dp[h-1][w-1] << endl;
    else cout << dp[h-1][w-1] + 1 << endl;

    return 0;
}
