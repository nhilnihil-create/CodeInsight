#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>> &pq) {return (ll)pq.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>, greater<T>> &pq) {return (ll)pq.size(); }
ll sz(string &s) {return (ll)s.size(); } 
ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b; }
bool checkindex(ll i,ll n){ return (i < n && i >= 0); }



int main(){
    ll n,t;
    cin >> n >> t;
    ll a[n],b[n];
    rep(i,0,n) cin >> a[i] >> b[i];
    ll dp[2][n+1][t+1];
    rep(i,0,2) rep(j,0,n+1) rep(k,0,t+1) dp[i][j][k] = 0;

    rep(i,0,n){
        rep(j,0,t){
            // 0 -> 0
            dp[0][i+1][j] = max(dp[0][i+1][j],dp[0][i][j]);
            if(j+a[i] <= t) dp[0][i+1][j+a[i]] = max(dp[0][i+1][j+a[i]],dp[0][i][j]+b[i]); 

            // 1 -> 1
            dp[1][i+1][j] = max(dp[1][i+1][j],dp[1][i][j]);
            if(j+a[i] <= t) dp[1][i+1][j+a[i]] = max(dp[1][i+1][j+a[i]],dp[1][i][j]+b[i]); 

            // 0 -> 1
            dp[1][i+1][j] = max(dp[1][i+1][j],dp[0][i][j]+b[i]);
        }
    }

    ll ans = 0;
    rep(i,0,t) ans = max(ans,dp[1][n][i]);
    rep(i,0,t+1) ans = max(ans,dp[0][n][i]);

    cout << ans << endl;
    
    return 0;
}

