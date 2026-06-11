#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
ll c;
vector<pl> g[100100];
ll ans[100100];

void dfs(ll n,ll p){
	if(g[n].size() == 0)return;
	//cout << n <<" " << g[n].size() << endl;
	ll color = p+1;
	color %= c;
	for(auto d:g[n]){
		ans[d.second] = color;
		dfs(d.first,color);
		color++;
		color %= c;
	}
	return;
}

signed main(){
	//cout << fixed << setprecision(10);
	ll n;
	cin >> n;
	rep(i,0,n-1){
		ll a,b; cin >> a >> b;
		--a; --b;
		g[a].push_back(pl(b,i));
	}
	rep(i,0,n){
		ll k = g[i].size();
		if(i != 0)k++;
		chmax(c,k);
	}
	ans[0] = 0;
	dfs(0,0);
	cout << c << endl;
	rep(i,0,n-1)cout << ans[i] + 1 << endl;

	return 0;
}