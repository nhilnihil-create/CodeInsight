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

signed main(){
	int n,m; cin>>n>>m;
	vl vec(n);
	rep(i,0,n)cin>>vec[i];
	sort(all(vec));
	while(m--){
		ll k=vec[n-1];
		vec.pop_back();
		k/=2;
		auto ind=lower_bound(all(vec),k);
		vec.insert(ind,k);
	}
	ll ans=0;
	rep(i,0,n)ans+=vec[i];
	cout<<ans<<endl;
	
	return 0;
}