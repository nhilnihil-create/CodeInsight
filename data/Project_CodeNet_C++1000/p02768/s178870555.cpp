#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

ll mod_pow(ll x,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
long long modinv(long long a){
    long long b=MOD,u=1,v=0;
    while(b){
      long long t=a/b;
      a-=t*b;
      swap(a,b);
      u-=t*v;
      swap(u,v);
    }
    u%=MOD;
    if(u<0) u+=MOD;
    return u;
}
 
long long dev(long long a,long long b){
    return (a*modinv(b))%MOD;
}
 
long long comb(int x,int y){
  long long tmp=1;
    for(int i=0;i<y;i++){
        tmp=dev(tmp*(x-i)%MOD,i+1);
    }
  return tmp;
}


int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,A,B; cin>>N>>A>>B;
    ll tmp=mod_pow(2,N,MOD)-1;
    tmp-=comb(N,A);
    if(tmp<0) tmp+=MOD;
    tmp-=comb(N,B);
    if(tmp<0) tmp+=MOD;
    cout<<tmp<<endl;
}
