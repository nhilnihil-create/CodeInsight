#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,m,a[2005],b[2005],dp[2005][2005],prfx[2005];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<m;i++)cin>>b[i],prfx[i]=1;
    dp[0][0]=1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++)if(a[i]==b[j])dp[i+1][j+1]=prfx[j];
        ll prv=0;
        for(ll j=0;j<m;j++){
            prv+=dp[i+1][j];
            prv%=mod;
            prfx[j]+=prv;
            prfx[j]%=mod;
        }
    }
    ll ans=0;for(ll i=0;i<=n;i++)for(ll j=0;j<=m;j++)ans+=dp[i][j],ans%=mod;
    cout<<ans;
}
