#include <iostream>
#include<time.h>
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
#include<cctype>
#include<iterator>
#include<unordered_map>
#include <cassert>
#include <bit>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
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
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
const int MOD = 1000000007;
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
#define greater greater<int>()
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
using Edge=pair<int,ll>;
using Graph=vector<vector<ll> >;//ll or Edge
using Edge=pair<int,ll>;
//const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// g++ -o a a.cpp -Wall -lm -std=c++17
inline ll mod_pow(ll x,ll n,ll mod=(ll)MOD){
    ll res=1;
    while(n>0){
    if(n&1)res=res*x%mod;
    x=x*x%mod;n>>=1;
    }
    return res;
}//x^n%mod
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

int main(){
    ll n,a,b;cin>>n>>a>>b;
    ll res=mod_pow(2,n)-1;
    cout<<(res-nCr(n,a)-nCr(n,b)+2*MOD)%MOD<<endl;
}