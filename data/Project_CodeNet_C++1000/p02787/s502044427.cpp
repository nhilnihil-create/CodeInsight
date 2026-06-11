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
	vvl dp(n+10,vl(hp+1,MOD));
	dp[0][0]=0;
	rep(i,0,n){
		rep(j,0,hp+1){
			chmin(dp[i+1][j],dp[i][j]);
			chmin(dp[i+1][min(j+a[i],hp)],dp[i+1][j]+b[i]);
		}
	}
	cout<<dp[n][hp]<<endl;
	return 0;
}