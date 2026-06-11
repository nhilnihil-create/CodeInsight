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
vl ans;

void dfs(int n,int p,vvl &g)
{
	for(int c:g[n]){
		if(c==p)continue;
		ans[c]+=ans[n];
		dfs(c,n,g);
	}
	return;
}

signed main(){
	int n,q; cin>>n>>q;
	vvl g(n,vl(0));
	ans.resize(n);
	rep(i,0,n-1){
		int a,b; cin>>a>>b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	while(q--){
		int p,x; cin>>p>>x;
		ans[p-1]+=x;
	}
	dfs(0,-1,g);
	rep(i,0,n) cout<<ans[i]<<'\n';
	return 0;
}
