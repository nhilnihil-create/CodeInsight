#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(x) (x).begin(),(x).end()
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
    ll n,d,a;cin>>n>>d>>a;
    vll x(n);
    vl y(n),z(n,0);
    rep(i,n)cin>>x[i].F>>x[i].S;
    sort(all(x));
    rep(i,n)y[i]=x[i].F;
    ll ans=0;
    vl sum(1);
    sum[0]=0;
    ll t=0,k=0;
    rep(i,n){
        if(x[i].S-(t-sum[k])*a>0){
            int l=upper_bound(all(y),x[i].F+2*d)-y.begin()-1;
            z[l]++;
            ll p=(x[i].S-(t-sum[k])*a)/a;
            if((x[i].S-(t-sum[k])*a)%a>0)p++;
            ans+=p;
            t+=p;
            sum.PB(t);
        }
        k+=z[i];
    }
    cout<<ans<<endl;
}
