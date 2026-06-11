#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map <ll,bool>  mp;
int main() {
    ll k;
    cin>>k;
    ll digits=0;
    ll k1=k;
    while(k)    k/=10,digits++;
    ll now=0;
    for(ll i=1;i<=digits;i++){
        now*=10;
        now+=7;
    }
    if(now==k1){
        cout<<digits;
        return 0;
    }
    if(now<k1){
        now*=10;
        now+=7;
        digits++;
    }
    ll ans=-1;
    for(ll i=digits;;i++){
        if(mp[now]) break;
        mp[now]=1;
        if(!(now%k1)){
            ans=i;
            break;
        }
        now=now-(now/k1)*k1;
        now*=10;
        now+=7;
    }
    cout<<ans;
    return 0;
}
