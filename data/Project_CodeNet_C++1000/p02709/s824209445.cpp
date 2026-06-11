#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
#define int long long
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<ll,int>> v;
    rep(i,n){
        ll a; cin >> a;
        v.pb({a,i});
    }
    sort(ALL(v),greater<pair<ll,int>>());
    ll dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    rep(i,n+1){
        rep(j,n+1){
            if(i>0&&i+j-1<n) chmax(dp[i][j],dp[i-1][j]+abs(v[i+j-1].se-(i-1))*v[i+j-1].fi);
            if(j>0&&i+j-1<n) chmax(dp[i][j],dp[i][j-1]+abs(v[i+j-1].se-(n-j))*v[i+j-1].fi);
        }
    }
    ll ans=0;
    rep(i,n+1){
        chmax(ans,dp[i][n-i]);
    }
    cout << ans << endl;
}
