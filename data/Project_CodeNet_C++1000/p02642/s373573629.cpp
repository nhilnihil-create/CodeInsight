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
	ll n; cin>>n;
	vl vec(n);
	ll m=0;
	ll cnt=0;
	map<ll,ll> mp;
	rep(i,0,n){
		ll a; cin>>a;
		mp[a]++;
		chmax(m,a);
		vec[i]=a;
	}
	vector<bool> ok(m+2,true);
	rep(i,0,n){
		ll k=vec[i];
		k+=vec[i];
		while(k<=m){
			ok[k]=false;
			k+=vec[i];
		}
	}
	ll ans=0;
	rep(i,0,n){
		if(mp[vec[i]]>1)continue;
		if(ok[vec[i]])ans++;
	}
	cout<<ans<<endl;
	return 0;
}