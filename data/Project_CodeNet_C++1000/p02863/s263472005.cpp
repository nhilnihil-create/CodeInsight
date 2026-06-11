#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
	ll n,t; cin >> n >> t;
	vl a(n),b(n);
	rep(i,n) cin >> a[i] >> b[i];
	vvl dp(n+1,vl(t+1,0));
	vvl ep(n+1,vl(t+1,0));
	rep(i,n){
		rep(j,t+1){
			dp[i+1][j] = dp[i][j];
			if(j-a[i] >= 0) chmax(dp[i+1][j],dp[i][j-a[i]]+b[i]);
		}
	}
	ll ans = 0;
	for(ll i=n-1; i>=0; i--){
		rep(j,t){
			chmax(ans,b[i]+dp[i][j]+ep[i+1][t-1-j]);
		}
		rep(j,t+1){
			chmax(ans,dp[i][j]+ep[i+1][t-j]);
		}
		rep(j,t+1){
			ep[i][j] = ep[i+1][j];
			if(j-a[i] >= 0) chmax(ep[i][j],ep[i+1][j-a[i]]+b[i]);
		}
	}
	cout << ans << endl;
}
