#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF (9e18)
#define EPS (1e-6)
#define debug(...) do{\
	cerr<<__PRETTY_FUNCTION__<<" - "<<__LINE__<<\
	" : ("#__VA_ARGS__<<") = ";\
	_OUT(__VA_ARGS__);\
}while(0)
template<typename T>void _OUT(T x){cerr<<x<<endl;}
template<typename T,typename...I>void _OUT(T x,I ...tail){cerr<<x<<", ";_OUT(tail...);}
void INIT(){
	ios::sync_with_stdio(false); cin.tie(0);
}

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int fpow(int b,int p){
	b%=MOD;
	int ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

ll dp[110][110];

int32_t main() {
	INIT();
	//code...
	ll n,m; cin>>n>>m;
	vector<string> v(n);
	for(auto &i:v) cin>>i;
	if(v[0][0]=='#') dp[0][0]=1;
	else dp[0][0]=0;
	For(j,1,m-1) dp[0][j]=(v[0][j]=='#' && v[0][j-1]=='.')?dp[0][j-1]+1:dp[0][j-1];
	For(i,1,n-1) dp[i][0]=(v[i][0]=='#' && v[i-1][0]=='.')?dp[i-1][0]+1:dp[i-1][0];
	For(i,1,n-1) For(j,1,m-1){
		ll a=dp[i-1][j];
		if(v[i][j]=='#' && v[i-1][j]=='.') a++;
		ll b=dp[i][j-1];
		if(v[i][j]=='#' && v[i][j-1]=='.') b++;
		dp[i][j]=min(a,b);
	}
	cout<<dp[n-1][m-1]<<"\n";
	return 0;
}




















