#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1000000007;
ll mod(ll x){
        return ((x%M + M)%M);
    }
ll add(ll a, ll b){
        return mod(mod(a)+mod(b));
    }
ll mul(ll a, ll b){
        return mod(mod(a)*mod(b));
    }
ll minu(ll a, ll b){
        return mod(mod(a)-mod(b));
    }
ll power(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1) res=mul(res,a);
        b = b>>1;
        a=mul(a,a);
    }
    return res;
}
int main(){
    ll n;
    cin>>n;
    ll rem =0;
    for(ll i=0;i<(1e7);++i){
        rem=(rem*10 + 7)%n;
        if(rem==0){
            cout<<i+1;
            return 0;
        }
    }
    cout<<"-1";
    return 0; 
}