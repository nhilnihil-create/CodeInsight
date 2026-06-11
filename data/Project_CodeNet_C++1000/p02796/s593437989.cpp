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
using pl = pair<ll,ll>;
signed main(){
	ll n; cin>>n;
    vector<pl> vec(n);
	rep(i,0,n){
		ll a,b; cin>>a>>b;
		vec[i].first=a-b;
		vec[i].second=a+b;
	}
	sort(all(vec));
	ll ans=0;
	ll memo=10000000000;
	for(ll i=n-1;i>=0;--i){
		if(vec[i].second>memo)continue;
		ans++;
		memo=vec[i].first;

	}
    cout<<ans<<endl;
	
	return 0;
}