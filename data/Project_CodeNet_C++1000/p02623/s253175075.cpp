#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
const ll Maxn=2e5+10;
ll N,M,K;
ll a[Maxn],b[Maxn],prea[Maxn],preb[Maxn];
ll finds(ll nums){
    ll l=0,r=M;
    while(l<r){
        ll mid=(l+r)>>1;
        if(l==r-1){
            if(preb[r]<=nums){
                return r;
            }else{
                return l;
            }
        }
        if(preb[mid]>nums){
            r=mid-1;
        }else{
            l=mid;
        }
    }
    return l;
}
int main() {
    cin>>N>>M>>K;
    for(ll i=1;i<=N;i++)    cin>>a[i],prea[i]=prea[i-1]+a[i];
    for(ll i=1;i<=M;i++)    cin>>b[i],preb[i]=preb[i-1]+b[i];
    ll ans=0;
    for(ll i=0;i<=N;i++){
        ll pa=prea[i];
        if(prea[i]>K) break;
        ll bi=finds(K-pa);
        ans=max(ans,i+bi);
    }
    cout<<ans;
    return 0;
}
