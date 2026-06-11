#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    fastIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    vec h(200001);
    cin>>n>>k;
    rep(i,n) cin>>h[i];
    if(n==k){
        cout<<0;return 0;
    }
    ll dp[301][301]={0},inf=1e18,ans=inf;
    rep(i,n)rep(j,n+1) dp[i][j]=inf;
    rep(i,n) dp[i][1]=h[i];
    rep(i,n)rep(j,n)rep(k,i) dp[i][j+1]=min(dp[i][j+1],dp[k][j]+max((ll)0,h[i]-h[k]));
    rep(i,n) ans=min(ans,dp[i][n-k]);
    cout<<ans<<"\n";
}