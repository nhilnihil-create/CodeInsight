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
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
    int n;cin>>n;
    vll x(n);
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    rep(i,n){
        cin>>x[i].F>>x[i].S;
    }
    sort(all(x));
    vll d;
    rep(i,n-1){
        for(int j=i+1;j<n;++j){
            d.PB(MP((x[i].F-x[j].F),(x[i].S-x[j].S)));
        }
    }
    sort(all(d));
    ll a=d[0].F,b=d[0].S,cnt=1,ans=0;
    int z=d.size();
    for(int i=1;i<z;++i){
        if(a==d[i].F&&b==d[i].S){
            cnt++;
        }
        else{
            ans=max(ans,cnt);
            a=d[i].F;b=d[i].S;
            cnt=1;
        }
    }
    ans=max(ans,cnt);
    cout<<n-ans<<endl;
}