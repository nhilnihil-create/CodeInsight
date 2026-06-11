#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define d1(x)  cerr << #x << "--> " << x << endl
#define d2(x,y)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<endl
#define d3(x,y,z)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<" | " << #z << "--> "<< z<< endl
#define d4(x,y,z,w)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<" | " << #z << "--> "<< z << " | "<< #w << "--> " << w <<endl
#define vpll vector<pair<ll,ll>>
#define F first
#define S second
#define T ll tt; cin>>tt; while(tt--)
using namespace std;
ll mode=998244353;
const long long maxn=2e5+5;
const long long inf=99999999999;
ll __lcm(ll a, ll b){ return (a*b)/__gcd(a,b); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRand(ll l, ll r){ uniform_int_distribution<ll> uid(l, r); return uid(rng); }

ll power(ll x, ll y){  
	ll p=mode, res=1;
    x = x % p;
    while (y > 0) {  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}


void solve(){
	
	ll n,s;
	cin>>n>>s;
	vector<ll> v(n+1);
	for (int i=1;i<=n;i++) cin>>v[i];
	vector<vector<ll>> dp(n+1, vector<ll> (s+1, 0));
	dp[0][0]=1;
	
	for (int i=1;i<=n;i++){
		for (int j=0;j<=s;j++){
			dp[i][j]=(2*dp[i-1][j])%mode;
			if (j>=v[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-v[i]])%mode;
		}
	}
	cout<<dp[n][s]<<endl;
	
	return;
}

 
int main(){ 
    
    #ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
    #endif
    srand(time(0)); 
    
    ios::sync_with_stdio(0);
    cin.tie(0);
 	
	//T{ solve(); }
	solve();
	
	
	
	return 0;
	
}