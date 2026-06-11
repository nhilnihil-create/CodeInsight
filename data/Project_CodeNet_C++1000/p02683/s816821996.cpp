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
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
ll dp[55][55][5000];

signed main(){
	//cout << fixed << setprecision(10);
	ll n,m,x; cin>>n>>m>>x;
	vl c(n);
	vvl g(n,vl(m));
	rep(i,0,n){
		cin>>c[i];
		rep(j,0,m){
			cin>>g[i][j];
		}
	}
	ll ans=MOD;
	rep(i,0,1<<n){
		vl cnt(m);
		ll cost=0;
		rep(j,0,n){
			if(i>>j&1){
				cost+=c[j];
				rep(k,0,m)cnt[k]+=g[j][k];
			}
		}
		bool ok=true;
		rep(k,0,m)if(cnt[k]<x)ok=0;
		if(ok)chmin(ans,cost);
	}
	cout <<(ans==MOD ? -1:ans) <<endl;
		


	return 0;
}