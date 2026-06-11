#include <iostream>

typedef long long ll;

using namespace std;
const int MOD = 1e9 + 7;
 

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}




int main(){

    ll n,a,b;

    scanf("%lld %lld %lld",&n,&a,&b);

    ll ans;
     ans=(modpow(2,n,MOD)-1)%MOD;
    ll p1=1;
    ll q1=1;

    for(ll i=n;i!=n-a;--i){
        p1=p1*i%MOD;
    }
    for(ll i=1;i<=a;++i){
        q1=q1*i%MOD;
    }

    ans=(ans-modpow(q1,MOD-2,MOD)*p1%MOD)%MOD;

    ll p2=1;
    ll q2=1;

    for(ll i=n;i!=n-b;--i){
        p2=p2*i%MOD;
    }

    for(ll i=1;i<=b;++i ){
        q2=i*q2%MOD;
    }

     ans=(ans-modpow(q2,MOD-2,MOD)*p2%MOD)%MOD;


     ans=(ans+MOD)%MOD;

     cout<<ans<<endl;
}