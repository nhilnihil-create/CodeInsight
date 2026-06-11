#include <bits/stdc++.h>
using namespace std;
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

const ll Mod = 1e9 + 7;
// const ll Mod = 998244353;
const ll MAXN = 1e6;

void solve(){
    ll n,m;cin>>n>>m;
    bool a[n][m];
    char c;
    for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) {cin>>c;a[i][j]=(c=='.')?0:1;}

    vvll dp(n,vll(m,1e5));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(i==0&&j==0) dp[i][j]=a[i][j];
            if(i+1<n) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(ll)(a[i+1][j]&&!a[i][j]));
            if(j+1<m) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(ll)(a[i][j+1]&&!a[i][j]));
        }
    }
    cout<<dp[n-1][m-1]<<"\n";
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