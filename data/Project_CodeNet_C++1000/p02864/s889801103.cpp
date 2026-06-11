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
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    ll n,k;cin>>n>>k;
    vector<vector<vector<ll> > >dp(n+2,vector<vector<ll> >(k+1,vector<ll>(n+1,inf*inf)));
    vector<ll>a(n+1);
    REP(i,1,n+1){
        cin>>a[i];
    }
    dp[0][0][0]=0;
    rep(i,n+1){
        rep(j,k+1){
            rep(l,n+1){
                if(dp[i][j][l]==inf*inf)continue;
                if(a[l]>=a[i]){
                    dp[i+1][j][i]=min(dp[i][j][l],dp[i+1][j][i]);
                }else{
                    dp[i+1][j][i]=min(dp[i][j][l]+a[i]-a[l],dp[i+1][j][i]);
                }
                if(j<k){
                    dp[i+1][j+1][l]=min(dp[i+1][j+1][l],dp[i][j][l]);
                }
            }
        }
    }
    ll ans=inf*inf;
    rep(i,k+1){
        rep(j,n+1){
            ans=min(ans,dp[n+1][i][j]);
        }
    }
    cout<<ans<<endl;
}