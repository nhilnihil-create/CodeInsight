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
	ll n; cin>>n;
	if(n%2==1){
		cout<<0<<endl;
		return 0;
	}
	ll cnt=10;
	ll ans=0;
	while(cnt<=n){
		ans+=n/cnt;
		cnt*=5;
	}
	cout<<ans<<endl;
	return 0;
}