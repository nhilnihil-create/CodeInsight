#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(ll x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)
//試験導入
#define irep(i, end_i, begin_i) for (ll i = (ll)begin_i-1; i >= (ll)end_i; i--)
#define MAX 2000
ll fact[MAX+20];
long long INF = 1LL<<60;
ll mod=1e9+7;
void Init(ll t){
    fact[0]=1;
    rep(i,1,t){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
}
ll c(ll n,ll k){
    ll bunshi=fact[n];
    ll bunbo=fact[n-k]*fact[k]%mod;
    ll ret=bunshi*modinv(bunbo,mod)%mod;
    if(ret<0)ret+=mod;
    return ret;
}
int main( ){
    ll n,blue;
    cin>>n>>blue;
    ll red=n-blue;
    Init(MAX+10);
    rep(i,1,blue+1){
        if(i>=red+2){
            cout<<0<<endl;
            continue;
        }
        ll ans=c(blue-1,i-1)*c(red+1,i);
        ans%=mod;if(ans<0)ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}


