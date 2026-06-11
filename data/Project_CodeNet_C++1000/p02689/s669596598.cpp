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

signed main(){
	int n,m; cin>>n>>m;
	vi vec(n);
	rep(i,0,n)cin>>vec[i];
	vector<bool> ans(n);
	rep(i,0,m){
		int a,b; cin>>a>>b;
		--a; --b;
		if(vec[a]==vec[b]){
			ans[a]=1;
			ans[b]=1;
		}
		else if(vec[a]<vec[b]){
			ans[a]=1;
		}
		else ans[b]=1;
	}
	ll cnt=0;
	rep(i,0,n)if(!ans[i])cnt++;
	cout<<cnt<<endl;
	
}