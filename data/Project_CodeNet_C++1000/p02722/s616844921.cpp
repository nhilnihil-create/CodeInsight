#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;

    ll res = 0;
    map<ll,int> mp;
    for(ll i = 2; i*i <= n; i++){
        if((n)%i == 0){
            ll t = n;
            while(t%i==0) t/=i;
            if(t%i == 1){
                mp[i] = 1;
                res++;
            } 
            ll tt = n/i;
            t = n;
            while(t%tt == 0) t/=tt;
            if(t%tt==1 && !mp[tt]){
                mp[tt] = 1;
                res++;
            }
        }
    }
    
    for(ll i = 2; i*i <= n-1; i++){
        if((n-1)%i == 0 && !mp[i]){
            mp[i] = 1;
            res++;
            ll tt = (n-1)/i;
            if(!mp[tt]){
                mp[tt] = 1;
                res++;
            }
        }
    }
    if(n == 2) cout<<1;
    else cout<<res+2;
}
