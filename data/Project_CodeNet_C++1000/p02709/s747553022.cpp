#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(10) << num << endl;
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    ll n; cin >> n;
    vector<Pll> a(n);
    rep(i,n){
        cin >> a[i].fi;
        a[i].se=i+1;
    }
    sort(ALL(a));
    reverse(ALL(a));
    ll dp[n+1][n+1];
    rep(i,n+1)rep(j,n+1) dp[i][j]=0;
    rep(i,n+1){
        rep(j,n+1){
            if(i>0&&i+j-1<n) chmax(dp[i][j],dp[i-1][j]+a[i+j-1].fi*(a[i+j-1].se-i));
            if(j>0&&i+j-1<n) chmax(dp[i][j],dp[i][j-1]+a[i+j-1].fi*(n+1-j-a[i+j-1].se));
        }
    }
    ll ans=0;
    rep(i,n+1) chmax(ans,dp[i][n-i]);
    cout << ans << endl;
    return 0;
}

