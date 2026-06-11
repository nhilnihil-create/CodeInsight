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
#define INF 1000000000000000000
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

int main(){
    int n;cin>>n;
    vl a(n+1),b(n+1,0);
    rep(i,n+1)cin>>a[i];
    if(n==0){
        if(a[0]==1)cout<<1<<endl;
        else cout<<-1<<endl;
    }
    else{
        if(a[0]!=0)cout<<-1<<endl;
        else{
            b[0]=1;
            for(int i=1;i<=n;++i){
                b[i]=min((ll)INF,2*b[i-1]-a[i]);
                if(b[i]<0||(b[i]==0&&i!=n)){
                    cout<<-1<<endl;
                    return 0;
                }
            }
            b[n]=0;
            for(int i=n-1;i>=0;--i){
                b[i]=min(a[i+1]+b[i+1],b[i]);
            }
            ll ans=0;
            rep(i,n+1)ans+=a[i]+b[i];
            cout<<ans<<endl;
        }
    }
}
