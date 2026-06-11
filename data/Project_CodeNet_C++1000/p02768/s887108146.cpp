#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

long long pow(long long a,long long b,long long mod){
    if(b==0){
        return 1;
    }else{
        if(b%2==0){
            return pow(a*a%mod,b/2,mod);
        }else{
            return pow(a*a%mod,b/2,mod)*a%mod;
        }
    }

}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    ll mod=10e8+7;

    ll ans=pow(2,n,mod)-1;
    ll nca,ncb;
    ll comb=1;
    for(int i=1;i<=b;i++){
        comb*=(n+1-i);
        comb%=mod;
        comb*=modinv(i,mod);
        comb%=mod;
        if(i==a){
            nca=comb;
        }
    }
    ncb=comb;
    ans-=nca;
    ans+=mod;
    ans%=mod;
    ans-=ncb;
    ans+=mod;
    ans%=mod;
    cout<<ans<<endl;
    
    return 0;
}