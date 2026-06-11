#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=3e3+69,INF=1e16;
struct vl{
    ll x,y;
    bool operator<(vl t)const{
        return x<t.x;
    }
};
ll n,t,ans;
vl a[MAXN];
ll dp[MAXN*2];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>t;
    for(ll i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n);
    fill(dp,dp+MAXN*2,-INF);
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=t-1;j>=0;j--)if(dp[j]!=-INF){
            dp[j+a[i].x]=max(dp[j+a[i].x],dp[j]+a[i].y);
            ans=max(ans,dp[j+a[i].x]);
        }
    }
    cout<<ans;
}