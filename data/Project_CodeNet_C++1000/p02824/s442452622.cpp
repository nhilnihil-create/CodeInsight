#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max=1e5+7;
ll a[Max];
ll temp[Max];
ll n,m,v,p;
bool check(ll x){
    ll cnt=0;
    for(int i=1;i<=n;i++){
        temp[i]=a[i];
    }
    for(int i=1;i<p;i++){
        temp[i]+=m;
        cnt++;
    }
    for(int i=x;i<=n;i++){
        temp[i]+=m;
        cnt++;
    }
    if(cnt>=v){
        return temp[p]<=temp[x];
    }else{
        ll left=1ll*(v-cnt)*m;
        for(int i=p;i<x;i++){
            if(temp[i]>temp[x]){
                return 0;
            }
            ll t=min(temp[x]-temp[i],1ll*m);
            left-=t;
        }
        return left<=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>v>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<ll>());
    ll l=p;
    ll r=n;
    while(l<r){
        ll mid=l+r+1>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l<<endl;
    return 0;
}