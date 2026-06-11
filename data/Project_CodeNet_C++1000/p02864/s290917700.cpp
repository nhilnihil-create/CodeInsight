#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
 #define int ll
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=1e9+7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int mul(int a,int b)
{
	return ((a)*1ll*(b))%mod;
}
 
void add_self(int &a,int b)
{
	a+=b;
	if(a>=mod)a-=mod;
}
 
int add(int a,int b){
	int c=a+b;
	if(c>=mod){
		c-=mod;
	}
	return c;
}
 
int sub(int a,int b){
	a-=b;
	if(a<0){
		a+=mod;
	}
	return a;
}
 
int powz(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1){
			res=mul(res,a);
		}
		b/=2;
		a=mul(a,a);
	}
	return res;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
	input>>x.F>>x.S;
	return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
	for(auto& i:x)
		input>>i;
	return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
	for(auto& i:x)
		output<<i<<' ';
	return output;
}
 
const int N=2000005;

ll dp[2][505][505];
 
void solve(){
	int n,k;
	cin>>n>>k;
	vi a(n);
	cin>>a;
    if(n<=k){
      cout<<0;
      return;
    }
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[0][i][j]=dp[1][i][j]=1e18;
		}
	}
	vector<int>compress;
	compress=a;
	sort(all(compress));
	compress.resize(unique(all(compress))-compress.begin());
	debug(compress);
	for(auto &i:a){
		i=lower_bound(all(compress),i)-compress.begin();
	}
	for(int prv=0;prv<compress.size();prv++){
		dp[0][1][a[prv]]=compress[a[prv]];
	}
	dp[0][0][a[0]]=compress[a[0]];
	dp[0][1][a[0]]=1e18;
	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			for(int prv=0;prv<compress.size();prv++){
				if(a[i]!=prv){
					dp[1][j+1][prv]=min(dp[1][j+1][prv],dp[0][j][prv]);
				}
				else{
					dp[1][j][prv]=min(dp[1][j][prv],dp[0][j][prv]);
				}
				dp[1][j][a[i]]=min(dp[1][j][a[i]],dp[0][j][prv]+max(0ll,compress[a[i]]-compress[prv]));
			}	
		}
		for(int j=0;j<=k;j++){
			for(int prv=0;prv<compress.size();prv++){
				dp[0][j][prv]=dp[1][j][prv];
				dp[1][j][prv]=1e18;
			}
		}
	}
	ll ans=1e18+700;
	for(int i=0;i<=k;i++){
		for(int prv=0;prv<compress.size();prv++){
			ans=min(ans,dp[0][i][prv]);
		}
	}
	cout<<ans;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	//~ cin>>tc;
	for(int _=0;_<tc;_++){
		//~ cout<<"Case #"<<_+1<<": ";
		solve();
		if(_!=tc-1)
		cout<<"\n";
	}
}
