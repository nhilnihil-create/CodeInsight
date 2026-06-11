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

int vis[1000000],dis[1000000];
vvi g(1000000);

int dfs(int v){
    if(vis[v]==2)return dis[v];
    vis[v]=1;
    for(auto x:g[v]){
        if(vis[x]==1)return -1;
        int y=dfs(x);
        if(y==-1)return -1;
        dis[v]=max(dis[v],y+1);
    }
    vis[v]=2;
    return dis[v];
}

int main(){
    int n;cin>>n;
    mem(dis,0);
    mem(vis,0);
    rep(i,n){
        int last=0;
        rep(j,n-1){
            int a;
            cin>>a;
            a--;
            int x=min(i,a),y=max(i,a);
            if(last==0){
                last=y+1000*x;
                g[0].PB(last);
                continue;
            }
            g[last].PB(y+1000*x);
            last=y+1000*x;
        }
    }
    dis[0]=-1;
    cout<<dfs(0)<<endl;
}
