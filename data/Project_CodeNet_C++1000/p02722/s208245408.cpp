#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vvll=vector<vll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;
using vpii=vector<pair<int,int>>;
using vpllll=vector<pair<ll,ll>>;

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

long long INF = 1LL<<60;
template<class T>bool is_prime(T IN){
    if(IN<=1)return false;
    for(long long i=2;i*i<=IN;i++){
        if(IN%i==0){
            return false;
        }
    }
    return true;
}
vector<pair<long long,long long>> primefact(long long x){vector<pair<long long,long long>> ret;for(long long i=1;i*i<=x;i++){if(x%i==0){vector<long long> alt={i,x/i};if(alt[0]==alt[1])alt[1]=1;for(long long j=0;j<alt.size();j++){if(is_prime(alt[j])){pair<long long,long long> t=make_pair(alt[j],0);while(x%alt[j]==0){x/=alt[j];t.second++;}ret.push_back(t); }}}}return ret;}
vll yakusuu(ll x){
    vll ret;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            ll a=x/i; ll b=i;
            if(a!=b){
                ret.push_back(a);
                ret.push_back(b);
            }
            else{
                ret.push_back(a);
            }
        }
    }
    return ret;
}
int main( ){
    ll n;
    cin>>n;
    ll res=0;
    auto pf=yakusuu(n-1);
    unordered_map<ll,int> cnt;
    for(auto v:pf){
        if(v==1)continue;
        cnt[v]++;
        res++;
    }

    vll v=yakusuu(n);
    for(auto p:v){
        if(p==1)continue;
        if(cnt.count(p))continue;
        ll dived=n;
        ll rem=0;
         while(dived%p==0){
            dived/=p;
        }
        if(dived%p==1)res++;
    }
    cout<<res<<endl;
    return 0;
}


