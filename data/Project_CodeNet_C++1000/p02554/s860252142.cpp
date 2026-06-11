#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#include <cstdio>
#include <cstring>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
#define mod 1000000007
//#define mod 998244353
#define pi 3.1415926535
using namespace std;
struct __INIT{
    __INIT(){
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout<<fixed<<setprecision(15);
    }
}__init;

ll mpow(ll a,ll b){
    if(b == 0) return 1;
    if(b == 1) return a%mod;
    if(b%2 == 0) return mpow((a*a)%mod,b/2)%mod;
    else return (a%mod)*mpow((a*a)%mod,(b-1)/2)%mod;
}

//necessary mpow
#define N 2000000
ll fact[N+1],ifact[N+1];
void init_comb(){
    fact[0] = 1;
    ifact[0] = 1;
    rep1(i,N+1){
        fact[i] = (fact[i-1]*i)%mod;
    }
    ifact[N] = mpow(fact[N],mod-2);
    for(ll i=N;i>0;--i) ifact[i-1] = (ifact[i]*i)%mod;
}
ll mcomb(ll a,ll b){
    if(a<b) return 0;
    if(a==b) return 1;
    return (((fact[a]*ifact[b])%mod)*ifact[a-b])%mod;
}


int main(){
    ll n;
    cin>>n;
    init_comb();
    ll ans = 0;
    rep1(i,n+1){
        ans = (ans+(mcomb(n,i)*(mpow(9,n-i)-mpow(8,n-i)+mod)%mod)%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}