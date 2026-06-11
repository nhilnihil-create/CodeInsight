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
vll Zalgo(const string &s){
   ll n=s.size();;
   vll ret(n,0);
   ret[0]=n;
   ll cmpbeg=1;
   ll same=0;
   while(cmpbeg<n){
       while(same+cmpbeg<n&&s[same]==s[same+cmpbeg])same++;
       ret[cmpbeg]=same;
       if(same==0){
           cmpbeg++;
           continue;
       }
       ll cpyfrom=1;
       while(cpyfrom+cmpbeg<n&&ret[cpyfrom]+cpyfrom<same){
           ret[cmpbeg+cpyfrom]=ret[cpyfrom];
           cpyfrom++;
       }
       cmpbeg+=cpyfrom;
       same-=cpyfrom;
   }
   return ret;
}
int main( ){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll res=0;
    rep(i,0,n){
        string t=s.substr(i);
        vll lcp=Zalgo(t);
        rep(j,0,t.size()){
            chmax(res,min(j,lcp[j]));
        }
    }
    cout<<res<<endl;
    return 0;
}


