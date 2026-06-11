#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int a,b,m; cin>>a>>b>>m;
	vi va(a),vb(b);
	rep(i,0,a) cin>>va[i];
	rep(i,0,b) cin>>vb[i];
	ll ans=MOD;
	rep(i,0,m){
		int x,y,c; cin>>x>>y>>c;
		--x; --y;
		ll v=va[x]+vb[y]-c;
		ans=min(ans,v);
	}
	sort(all(va));
	sort(all(vb));
	ll d=va[0]+vb[0];
	ans=min(ans,d);
	cout<<ans;
	
	
	return 0;
}