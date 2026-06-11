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
int main( ){
    string s;
    cin>>s;
    string t;
    cin>>t;
    ll loop=0,pos=0;
    set<int> eachpos[26];
    int sn=s.size(),tn=t.size();
    rep(i,0,s.size()){
        eachpos[s[i]-'a'].insert(i);
    }
    rep(i,0,t.size()){
        if(eachpos[t[i]-'a'].empty()){
            cout<<-1<<endl;
            return 0;
        }
        auto itr=eachpos[t[i]-'a'].lower_bound(pos);
        if(itr==eachpos[t[i]-'a'].end()){
            loop++;
            pos=0;
            itr=eachpos[t[i]-'a'].lower_bound(pos);
        }
        pos=*itr;
        pos++;
    }
    cout<<loop*sn+pos<<endl;
    return 0;
}


