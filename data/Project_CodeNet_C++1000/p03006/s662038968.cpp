#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll x[105],y[105];
ll par[105],sz[105];
ll find(ll i){
    if(par[i]==i)
    return i;
    return par[i]=find(par[i]);
}
void merge(ll a,ll b){
    a=find(a);
    b=find(b);
    if(a==b)
    return;
    if(sz[b]>sz[a])
    swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll res=n;
    for(ll i=0;i<n;i++)
    cin>>x[i]>>y[i];
    for(ll a=0;a<n;a++)
    for(ll b=a+1;b<n;b++){
        ll p=x[b]-x[a],q=y[b]-y[a],sum=0;
        for(ll i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
        for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        if((x[i]-x[j]==p)&&(y[i]-y[j]==q))
        merge(i,j);
        for(ll i=0;i<n;i++)
        if(par[i]==i)
        sum++;
        res=min(res,sum);
    }
    cout<<res;
}
