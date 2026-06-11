#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
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
const ll INF = 1 << 29;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const int MAX_V = 500;
// const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }





ll mod_pow(ll x,ll n, ll mod){
    if(n==0) return 1;
    ll res=mod_pow(x * x % mod, n/2, mod);
    if(n & 1) res=res * x % mod;
    return res;
}

ll gcd(ll a,ll b){
    if(b ==0) return a;
    return gcd(b,a%b);
}

map<ll,ll> res;
void prime_factor(ll n){
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            res[i]++;
            n/=i;
        }
    }
    if(n!=1) res[n]++;
    return;
}




void solve() {
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    ll cnt[500010]={};
    for(ll i = k;i>0;i--){
        ll a = k/i;
        ll sum = mod_pow(a,n,MOD);
        cnt[i] = sum;
        // ans += i * sum;
        // cout<<i<<" "<<a<<" "<<mod_pow(a,n,MOD)<<" "<<ans<<endl;
        ans%=MOD;
        for(ll j = 2*i;j <=k;j+=i){
            cnt[i] += MOD - cnt[j];
        }
    }

    rep2(i,1,k+1){
        ans+=i*cnt[i];
        ans%=MOD;
    }

    cout<<ans<<endl;


}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);


    ll t=1;
    
    // cin>>t;

    rep(i,t){
        solve(); 
    }

    return 0;
}
