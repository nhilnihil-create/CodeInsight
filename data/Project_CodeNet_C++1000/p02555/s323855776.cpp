
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>
#define  pll            pair<ll,ll>
#define  vv             vector<int>
#define  ff             first
#define  ss             second
#define  sz(v)          v.size()
#define  all(v)         v.begin(),v.end()

int const MOD=(int) 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }
const int N = 200007;
const int MAX=1000005;
int fact[20001];
int main()
{
    optimize
    ll s,n,ans=0;
    cin>>s;
    if(s<3){
        cout<<0<<endl;
        return 0;
    }
    n=s;
    int x=0;
    while(n-3>=3){
        n-=3;
        x++;
    }
    fact[0]=1;
    for(int i=1;i<=2000;i++) fact[i]=modMul(fact[i-1],i);
    for(int i=1;i<=x+1;i++){
        ll N=s-i*3;
        ll tmp=modDiv(fact[i+N-1],modMul(fact[N],fact[i-1]));
        ans=modAdd(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
