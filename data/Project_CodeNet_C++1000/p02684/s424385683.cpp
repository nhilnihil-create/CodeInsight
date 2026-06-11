#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n) a[i]--;
    map<ll,ll> data;
    ll i=0,now=0,t1=0,t2=0;
    while(1){
        data[now]++;
        if(data[now]==2&&t1==0) t1=i;
        if(data[now]==3){
            t2=i;
            break;
        }
        now=a[now];
        i++;
    }
    t2-=t1;
    t1-=t2;
    ll ans=0;
    if(k<=t1){
        for(ll ii=0;ii<k;ii++){
            ans=a[ans];
        }
        cout<<ans+1;
    }
    else{
        for(ll ii=0;ii<(k-t1)%t2+t1;ii++){
            ans=a[ans];
        }
        cout<<ans+1;
    }
}