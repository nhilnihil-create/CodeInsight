#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//cout << fixed << setprecision();
//priority_queue<ll, vector<ll>, greater<ll>> q;
signed main(){
	ll hp,n; cin>>hp>>n;
	vl a(n),b(n);
	rep(i,0,n)cin>>a[i]>>b[i];
	vvl dp(n+10,vl(100000,MOD));
	dp[0][0]=0;
	rep(i,0,n){
		rep(j,0,100000){
			ll k=dp[i][j];
			if(j-a[i]>=0)chmin(k,dp[i+1][j-a[i]]+b[i]);
			dp[i+1][j]=k;
		}
	}
	ll ans=MOD;
	rep(i,hp,100000)chmin(ans,dp[n][i]);
	cout<<ans<<'\n';
	return 0;
}