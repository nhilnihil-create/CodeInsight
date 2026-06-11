#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define odd(x) ((x)&1)
#define even(x) (!odd(x))
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(auto i=0;i<n;++i)
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST_CASE int tc;cin>>tc;while(tc--)

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define JD

/******************************************************************************************************************************/

#include <chrono>
#define Clock std::chrono::high_resolution_clock::now()
// #define TIME

const ll inf = 2e18;
const ll N = 2e5+3;
const ll mod = 2019;


int main()
{
    auto start_time = Clock;
    FASTIO

    #ifndef JD
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    vector<vll> dp(2,vll(mod));
    ++dp[0][0];

    string s;
    cin>>s;
    ll n = s.size();
    vll v(n+1);
    rep(i,n){
    	v[i+1]=s[i]-'0';
    }

    ll p{0},ans{0},f{1};

    for(ll i=1;i<=n;++i){
	    
	    rep(j,mod){
	    	ll g = (j*10)%mod;	
	    	dp[f][g]+=dp[f^1][j];
	    	dp[f^1][j]=0;
	    }

    	p *= 10;
    	(p += v[i]) %= mod;
    	ans += dp[f][p];
    	++dp[f][p];
    	f^=1;

    }
    cout<<ans<<"\n";



    


    auto end_time = Clock;
    #ifndef TIME
    	return 0;
    #endif
	cout << "\nTime elapsed: "
	<< (double)chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count() 
	<< "ms\n";


    return 0;
}

