#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

int main(){
    int k,q;
    cin>>k>>q;
    ll d[k];
    for(int i=0;i<k;++i){
        cin>>d[i];
    }
    for(int i=0;i<q;++i){
        ll n,x,m;
        cin>>n>>x>>m;
        ll t=0;
        for(int j=0;j<k;++j){
            t+=(d[j]%m);
            if(d[j]%m==0){
                t+=m;
            }
        }
        ll ans=x%m;
        ans+=t*((n-1)/k);
        ll rest=n-1-(n-1)/k*k;
        for(int j=0;j<rest;++j){
            ans+=(d[j]%m);
            if(d[j]%m==0){
                ans+=m;
            }
        }
        ans=ans/m;
        cout<<n-1-ans<<endl;
    }
}
