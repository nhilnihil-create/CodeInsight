#include <bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T> ostream& operator<<(ostream &os, set<T> V){
	os << "[ ";
	for(auto v  : V) os << v << " ";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, map<T , R> V){
	os << "[ ";
	for(auto v  : V) os << "(" << v.first << ":" << v.second << ")";
	return os << " ]";
}
template<class T , class R > ostream& operator<<(ostream &os, pair<T , R> V){
	return os << "(" << V.first << "," << V.second << ")";
}

#define cerr cout
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
    clock_t clk=clock();
    #define checktime() cout<<"\nTime Elapsed : "<<float(clock()-clk)/CLOCKS_PER_SEC<<endl
#else
    #define trace(...);
    #define checktime();
#endif
/*---------------------------Defines----------------------*/
typedef long long int ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
#define vbl vector<bool>
#define vvll vector<vll>
#define vld vector<ld>
#define vb vector<bool>
#define vc vector<char>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
/*-----------------------Modular Arithmetic---------------*/
inline ll add(ll x,ll y,ll mod){x+=y; if(x>=mod) return x-mod; return x;}
inline ll sub(ll x,ll y,ll mod){x-=y; if(x<0) return x+mod; return x;}
inline ll mul(ll x,ll y,ll mod){return (x*1ll*y)%mod;}
inline ll power(ll x,ll y,ll mod){ll ans=1; while(y){if(y&1) ans=mul(ans,x,mod); x=mul(x,x,mod); y>>=1;} return ans;}
inline ll inv(ll x,ll mod){return power(x,mod-2,mod);}
/*-----------------------------Code begins----------------------------------*/

const ll MOD = 998244353;

void solve(){
    ll n,s;cin>>n>>s;
    vll a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    // trace(n,s,a);
    vvll dp(n+1,vll(s+1,0));
    for(ll i=0;i<=n;i++) dp[i][0]=1LL;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=s;j++){
            dp[i][j]=mul(dp[i-1][j],2,MOD);
        }
        for(ll j=s;j>=a[i];j--){
            dp[i][j]=add(dp[i][j],dp[i-1][j-a[i]],MOD);
            // trace(i,j,dp[i][j]);
        }
    }
    cout<<dp[n][s]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<fixed<<setprecision(25);
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}