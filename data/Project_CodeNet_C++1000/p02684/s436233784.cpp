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
const int D = 60;
ll to[D][200005];

signed main(){
	//cout << fixed << setprecision(10);
	ll n,k; cin>>n>>k;
	rep(i,0,n)cin>>to[0][i],to[0][i]--;

	rep(i,0,D-1){
		rep(j,0,n){
			to[i+1][j]=to[i][to[i][j]];
		}
	}
	ll ans=0;
	for(int i=D-1; i>=0; --i){
		ll L=1ll<<i;
		if(L<=k){
			k-=L;
			ans=to[i][ans];
		}
	}
	cout << ans+1 << endl;



	return 0;
}