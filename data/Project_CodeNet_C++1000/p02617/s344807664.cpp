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
const int MAXN=10;
const ll MOD=10;
ll _gcd(ll a,ll b){if(b==0)return a;return _gcd(b,a%b);}
ll gcd(ll a,ll b){a=abs(a),b=abs(b);if(a<b)swap(a,b);return _gcd(a,b);}
ll qpow(ll a,ll n){ll rt=1;while(n){if(n&1)rt=(rt*a)%MOD;a=a*a%MOD;n>>=1;}return rt;}
ll factor[MAXN];
void cal_factor(){factor[0]=1;for(int u=1;u<MAXN;u++){factor[u]=(factor[u-1]*u)%MOD;}}
ll C(ll n,ll k){return factor[n]*qpow(factor[n-k],MOD-2)%MOD*qpow(factor[k],MOD-2)%MOD;}
void solve()
{
    int N;
    ll nv=0,ne=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    nv=N;
    for(int u=2;u<=N;u++){
        int s,t;
        cin>>s>>t;
        if(s>t)swap(s,t);
        nv+=(ll)u*(N-u+1);
        ne+=(ll)s*(N-t+1);
    }
    cout<<nv-ne;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}