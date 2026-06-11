#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
 

long long modpow(ll a, ll b) {
    ll res=1;
    while (b) {
        if (b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
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
    ll n,a,b,k,ans;
    cin>>n>>a>>b;
    ans=modpow(2,n)-1;
    ll tmp1=1,tmp2=1;
    rep(i,0,a){tmp1=tmp1*(n-i)%mod;tmp2=tmp2*(i+1)%mod;}
    ans=(ans-tmp1*modinv(tmp2,mod)%mod)%mod;
    tmp1=1,tmp2=1;
    rep(i,0,b){tmp1=tmp1*(n-i)%mod;tmp2=tmp2*(i+1)%mod;}
    ans=(ans-tmp1*modinv(tmp2,mod)%mod)%mod;

    cout<<(ans+mod)%mod;
}