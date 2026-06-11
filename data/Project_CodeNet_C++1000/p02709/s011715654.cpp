#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define PII pair<ll,ll>
const ll sz=2010;
ll dp[sz][sz];
ll n;
PII val[sz];

ll cholo(ll l,ll r,ll id)
{
    if(id>=n){
         return 0;
    }
    ll &ret=dp[l][r];
    if(~ret) return ret;

    ll mx=cholo(l+1,r,id+1)+(val[id].first*abs(l-val[id].second));
    mx=max(mx, cholo(l,r-1,id+1)+(val[id].first*abs(r-val[id].second)));
    return (ret=mx);
}

int main()
{
    ll m,p,q;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>val[i].first;
        val[i].second=i;
    }
    sort(val,val+n,greater<PII>());
    memset(dp,-1,sizeof dp);
    ll ans=cholo(0,n-1,0);
    cout<<ans<<'\n';
}

