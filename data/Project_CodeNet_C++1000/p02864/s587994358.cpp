#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9+7;
const int MAX = 5100000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
#define INT_MAX 1e9+7
vector<ll> fac(MAX), finv(MAX), inv(MAX);

int main(){
    ll n,K; cin >> n >> K;
    vl h(n+1,0);
    REP(i,1,n+1) cin >> h[i];
    ll dp[n+1][K+1][n+1];
    rep(i,n+1) rep(j,K+1) rep(k,n+1) dp[i][j][k] = linf;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,K+1){
            rep(k,i+2){
                if(j<K) chmin(dp[i+1][j+1][k], dp[i][j][k]);
                chmin(dp[i+1][j][i+1], dp[i][j][k] + max(0LL,h[i+1]-h[k]));
            }
        }
    }
    ll ans = linf;
    rep(i,K+1)rep(j,n+1) chmin(ans, dp[n][i][j]);
    /*rep(i,n+1){
        rep(j,K+1){
            rep(k,n+1) cout << dp[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }*/
    cout << ans << endl;
}
