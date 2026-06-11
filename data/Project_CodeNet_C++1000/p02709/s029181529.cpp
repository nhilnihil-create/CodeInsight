#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<vector<ll> >dp(n+1,vector<ll>(n+1,-1));
    vector<pll>p(n);
    rep(i,n){
        p[i]=mp(a[i],i);
    }
    sort(rall(p));
    dp[0][0]=0;
    rep(i,n){
        rep(j,n){
            if(dp[i][j]<0)continue;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+p[i].first*abs(n-1-(i-j)-p[i].second));
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+p[i].first*abs(p[i].second-j));
        }
    }
    ll ans=0;
    rep(i,n+1){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
}