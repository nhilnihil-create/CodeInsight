#include <iostream>
#include<string>
#include<cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<stack>
#include<set>
#include <limits>
#include <climits>
#include <numeric>
#include<cassert>
using namespace std;
typedef long long ll;
typedef vector<ll>VI;
typedef vector<bool>VB;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define bitrep(bit,A) for(int bit=A; ;bit=(bit-1)&A)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) (ll)((a).size())
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define SORT(c) stable_sort(ALL(c))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX_N 200100
#define MAX_B 1001001//6
#define MAX_S 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
#define MOD 1000000007
#define INF 1<<30
#define INFTY 1000000000000000001LL
#define MAX_INT INT_MAX
#define Endl '\n'
#define mian() main()
#define greater greater<int>()
VI findAll(string S,string pattern){VI P;ll pos=(ll)S.find(pattern);
while(pos!=string::npos){P.push_back(pos);pos=(ll)S.find(pattern,pos+1);}return P;}
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
bool is_prime(ll n){if(n<2)return 0;for(int i=2;i*i<n;i++)if(n%i==0)return 0;return 1;}
inline void eratosthenes(VB& p){rep(i,SZ(p))p[i]=1;p[0]=p[1]=0;
rep(i,SZ(p)/2+1){if(p[i])for(ll j=i+i;j<SZ(p);j+=i)p[j]=0;}}
inline ll mod_add(ll a,ll b){return (a+b)%MOD;}
inline ll mod_sub(ll a,ll b){return (a+MOD-b)%MOD;}
inline ll mod_mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
inline ll mod_pow(ll x,ll n,ll mod=(ll)MOD){ll res=1;while(n>0){
if(n&1)res=res*x%mod;x=x*x%mod;n>>=1;}return res;}
inline ll mod_inv(ll x){return mod_pow(x,MOD-2);}
inline ll mod_div(ll a, ll b){return mod_mul(a,mod_inv(b));}
using Graph=vector<vector<P> >;
ll nCr(ll n,ll k,ll MOD_=1000000007){
    //assert(n>=0&&k>=0&&MOD_>=2);
    ll size=k;
    ll ans=1;
    vector<ll>fact_inv,inv;
    fact_inv.resize(size+5);
    inv.resize(size+5);
    fact_inv[0]=fact_inv[1]=1;
    inv[1]=1;
    for(int i=2;i<size+5;i++){
        inv[i]=MOD_-inv[MOD_%i]*(MOD_/i)%MOD_;
        fact_inv[i]=fact_inv[i-1]*inv[i]%MOD_;
    }
    for(int i=n;i>=n-k+1;i--){
        ans*=i;ans%=MOD_;
    }
    return ans*fact_inv[k]%MOD_;
}
int k,n;
int main(){
    cin>>n>>k;
   for(int i=1;i<=k;i++){
       ll a=nCr(n-k+1,i);
       ll b=nCr(k-1,i-1);
       ll x=a*b%MOD;
       cout<<x<<endl;
   }
}