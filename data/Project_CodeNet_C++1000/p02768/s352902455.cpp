#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
const int MAXN=2e5+10;
const ll MOD=1e9+7;
ll _gcd(ll a,ll b){if(b==0)return a;return _gcd(b,a%b);}
ll gcd(ll a,ll b){a=abs(a),b=abs(b);if(a<b)swap(a,b);return _gcd(a,b);}
ll qpow(ll a,ll n){ll rt=1;while(n){if(n&1)rt=(rt*a)%MOD;a=a*a%MOD;n>>=1;}return rt;}
ll factor[MAXN];
void cal_factor(){factor[0]=1;for(int u=1;u<MAXN;u++){factor[u]=(factor[u-1]*u)%MOD;}}
ll C(ll n,ll k){return factor[n]*qpow(factor[n-k],MOD-2)%MOD*qpow(factor[k],MOD-2)%MOD;}
ll Cnk(ll n,ll k)
{
    ll up=1,dn=1;
    for(ll t=n;t>n-k;t--)up=up*t%MOD;
    for(ll t=1;t<=k;t++){
        dn=dn*t%MOD;
    }
    return up*qpow(dn,MOD-2)%MOD;
}
void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans=qpow(2,n)-1;
    ans=(ans-Cnk(n,a)+MOD)%MOD;
    ans=(ans-Cnk(n,b)+MOD)%MOD;
    cout<<ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}