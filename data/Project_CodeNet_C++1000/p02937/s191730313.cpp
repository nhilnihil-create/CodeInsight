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
    string S,T;
    cin>>S>>T;
    int N=S.size();
    vvi loc(N*2,vi(26,-1));
    irep(l,0,2*N-1){
        rep(c,0,26){
            if(S[(l+1)%N]-'a'==c){
                loc[l][c]=l+1;
            }
            else{
                loc[l][c]=loc[l+1][c];
            }
        }
    }
    int si=0;
    ll ans=0;
    if(S[0]==T[0])T.erase(0,1);
    rep(i,0,T.size()){
        if(loc[si][T[i]-'a']==-1){
            cout<<-1<<endl;
            return 0;
        }
        ans+=loc[si][T[i]-'a']-si;
        si=(loc[si][T[i]-'a'])%N;
    }
    cout<<ans+1<<endl;
    return 0;
}


