#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
// #define ll int
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



ll mod_pow(ll x,ll n, ll mod){
    if(n==0) return 1;
    ll res=mod_pow(x * x % mod, n/2, mod);
    if(n & 1) res=res * x % mod;
    return res;
}

ll extgcd(ll a, ll b, ll& x, ll& y){
    ll d=a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }
    else{
        x=1;y=0;
    }
    return d;
}

ll mod_inverse(ll a,ll mod){
    ll x,y;
    extgcd(a,mod,x,y);
    return (mod+x%mod)%mod;
}


void solve(){
    ll n;
    ll a[10];
    cin>>n>>a[0]>>a[1];
    ll ans=mod_pow(2,n,MOD);
    ans--;
    rep(i,2){
        ll sum=1,sum1=1;
        rep(j,a[i]){
            sum*=(n-j);
            sum%=MOD;
        }
        rep2(j,1,a[i]+1){
            sum1*=j;
            sum1%=MOD;
        }
        ll s=sum*mod_inverse(sum1,MOD)%MOD;
        ans+=MOD;
        ans-=s;
        ans%=MOD;

    }
      
    
    cout<<ans<<endl;
    
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    
     

    solve(); 


    return 0;
}
