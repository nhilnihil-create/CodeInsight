#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll n,m;cin>>n>>m;
    vector<ll> s(n),t(m);

    rep(i,n) cin>>s[i];
    rep(i,m) cin>>t[i];

    vector<vector<ll>> dp(2010,vector<ll>(2010,0));
    vector<vector<ll>> sum(2010,vector<ll>(2010,0));
    
    //基本的にはTLE解と同じ
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=sum[i-1][j-1]+1;
                dp[i][j]%=mod;
            }

            sum[i][j]=(sum[i][j]+sum[i-1][j]);
            if(sum[i][j]>=mod) sum[i][j]-=mod;
            sum[i][j]=(sum[i][j]+sum[i][j-1]);
            if(sum[i][j]>=mod) sum[i][j]-=mod;
            sum[i][j]=(sum[i][j]-sum[i-1][j-1]);
            if(sum[i][j]<0) sum[i][j]+=mod;
            sum[i][j]=(sum[i][j]+dp[i][j]);
            if(sum[i][j]>=mod) sum[i][j]-=mod;
        }
    }

    ll ans=1;
    rep(i,n+1){
        rep(j,m+1){
            ans+=dp[i][j];
            ans%=mod;
        }
    }

    cout<<ans<<endl;
    return 0;
}