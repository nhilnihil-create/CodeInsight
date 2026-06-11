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

int main(){
    int n,k;cin>>n>>k;
    vi a(n),b;
    int sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    b.PB(1);b.PB(sum);
    for(int i=2;i*i<=sum;++i){
        if(sum%i==0){
            b.PB(i);
            if(i!=sum/i){
                b.PB(sum/i);
            }
        }
    }
    sort(all(b));
    int ans=1;
    for(int i=0;i<b.size();++i){
        vi c(n);
        rep(j,n){
            c[j]=a[j]%b[i];
        }
        sort(all(c));
        deque<int>d;
        rep(j,n){
            d.PB(c[j]);
        }
        int sum1=0,sum2=0;
        while(!d.empty()){
            while(sum1>=sum2&&!d.empty()){
                int u=d.back();
                d.pop_back();
                sum2+=b[i]-u;
            }
            while(sum1<sum2&&!d.empty()){
                int f=d.front();
                d.pop_front();
                sum1+=f;
            }
        }
        if(sum1<=k)ans=b[i];
    }
    cout<<ans<<endl;
}
