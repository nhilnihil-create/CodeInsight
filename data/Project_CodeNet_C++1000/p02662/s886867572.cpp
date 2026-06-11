#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
#define FOR(i, s, n) for (ll i = (s); i < (n); ++i)
#define FORALL(i, n) for (ll i = 0; i < (n); ++i)
#define MOD 998244353
#define ff first
#define ss second
#define pll pair<long long, long long>
#define fast ios_base::sync_with_stdio(false)
#define countbits(x) __builtin_popcount(x)
#define pb(x) push_back((x))
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define print(x) cout << x << endl
#define debug print("reaching\n")
#define mll map<ll,ll>
#define lsb(i) i&(-i)
#define printv(x)            \
    FORALL(i, x.size())      \
    {                        \
        cout << x[i] << ' '; \
    }                        \
    cout << endl            \
;
#define input(v,x)  \
    FORALL(i,n)     \
    {               \
        cin>>v[i];  \
    }               \
;
#define printm(m) \
    for(auto i: m){\
        cout<<i.ff<<' '<<i.ss<<endl;        \
    }\
;
long long pow2(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%MOD) * (a%MOD))%MOD;
        a = ((a%MOD) * (a%MOD));
        b >>= 1;
    }
    return res;
}

template <typename T>
T extGcd(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

template <typename T>
T modInv(T a, T m)
{
    T x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}

int main()
{
    fast;
    // #ifndef ONLINE_JUDGE
    // // freopen("input.txt", "r", stdin);
    // // freopen("output.txt", "w", stdout);
    // #endif

    int t=1;
    // cin>>t;
    // ll tot=t;
    while(t--){
    	ll n,s;
    	cin>>n>>s;
    	ll dp[n+1][s+1];
    	memset(dp, 0, sizeof(dp));
    	vll v(n);
    	FORALL(i,n){
    		cin>>v[i];
    	}
    	int k = modInv(2, MOD);
    	dp[0][0] = pow2(2, n);
    	for(int i = 0; i<n;i++){
    		for(int j = 0; j<=s;j++){
    			dp[i+1][j] += dp[i][j];
    			dp[i+1][j]%=MOD;
    			if(j+v[i] <=s ) {
    				dp[i+1][j+v[i]] += (dp[i][j] * k )%MOD;
    				dp[i+1][j+v[i]]%=MOD;
    			}
    		}
    	}
    	print(dp[n][s]);
    }
    return 0;
}
