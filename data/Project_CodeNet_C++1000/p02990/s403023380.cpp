#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
const int mod = 1000000007;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
ll modchoose(int n,int a){
    ll x=1,y=1;
    rep(i,a){
        x=(x*(n-i))%mod;
        y=(y*(i+1))%mod;
    }
    return (x*modpow(y,mod-2))%mod; // x/y
}
 
int main(){
    int n,k;cin>>n>>k;
    vector<ll>  ans(k,0);
    int x=n-k+1;
    for(int i=0;i<k;i++){
        cout<<(modchoose(x,i+1)*modchoose(k-1,i))%mod<<endl;
    }

}