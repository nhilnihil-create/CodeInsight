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
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}

int main(){
    ll n,m; cin >> n >> m;
    vl s(n),t(m);
    rep(i,n) cin >> s[i];
    rep(j,m) cin >> t[j];
    vvl dp(n+1,vl(m+1,0));
    rep(i,n+1) dp[i][0] = 1;
    rep(j,m+1) dp[0][j] = 1;
    rep(i,n){
        rep(j,m){
            if(s[i]==t[j]) dp[i+1][j+1] = dp[i][j+1]+dp[i+1][j];
            else dp[i+1][j+1] = dp[i][j+1]+dp[i+1][j]-dp[i][j];
            if(dp[i+1][j+1]<0) dp[i+1][j+1] += mod;
            dp[i+1][j+1] %= mod;
        }
    }
    /*rep(i,n+1){
        rep(j,m+1) cout << dp[i][j] << " ";
        cout << endl;
    }*/
    cout << dp[n][m] << endl;
}